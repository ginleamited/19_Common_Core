/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:38:43 by jilin             #+#    #+#             */
/*   Updated: 2025/04/12 00:17:42 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_run(char **args, char *cmd, char **env)
{
    char **path;
    char *temp;
    char *cmd_path = NULL;
    int i;

    if (!cmd || !args || !args[0])
    {
        ft_free(args);
        exit(127);
    }

    path = ft_find_path(env);
    if (!path)
    {
        ft_putstr_fd("PATH not found\n", 2);
        ft_free(args);
        exit(127);
    }

    // First find the executable path
    i = 0;
    while (path[i])
    {
        temp = ft_strjoin(path[i], "/");
        if (!temp)
        {
            ft_free(path);
            ft_free(args);
            exit(1);
        }
        cmd_path = ft_strjoin(temp, cmd);
        free(temp);
        if (!cmd_path)
        {
            ft_free(path);
            ft_free(args);
            exit(1);
        }
        
        // Check if the file exists and is executable
        if (access(cmd_path, X_OK) == 0)
            break;
            
        free(cmd_path);
        cmd_path = NULL;
        i++;
    }

    // Clean up path array
    ft_free(path);
    
    // Execute the command if found
    if (cmd_path)
    {
        execve(cmd_path, args, env);
        free(cmd_path);  // If execve fails
    }
    
    // Command not found
    ft_putstr_fd("Failed to execute: ", 2);
    ft_putstr_fd(cmd, 2);
    ft_putstr_fd("\n", 2);
    ft_free(args);
    exit(127);
}

void ft_first_child(int fd[2], int file1, char *cmd, char **env)
{
    char **args;
    int devnull;
    
    // Close read end of pipe
    close(fd[0]);
    
    // Redirect stdin properly
    if (file1 >= 0)
    {
        // File opened successfully, use it as stdin
        if (dup2(file1, STDIN_FILENO) < 0)
        {
            perror("dup2");
            close(fd[1]);
            exit(1);
        }
        close(file1);
    }
    else
    {
        // File couldn't be opened, use /dev/null instead
        devnull = open("/dev/null", O_RDONLY);
        if (devnull >= 0)
        {
            dup2(devnull, STDIN_FILENO);
            close(devnull);
        }
    }
    
    // Redirect stdout to pipe write end
    if (dup2(fd[1], STDOUT_FILENO) < 0)
    {
        perror("dup2");
        close(fd[1]);
        exit(1);
    }
    close(fd[1]);
    
    // Rest of your code remains the same
    if (!cmd || cmd[0] == '\0')
        exit(0);
    
    args = ft_split(cmd, ' ');
    if (!args)
        exit(1);
    
    if (args[0] && args[0][0] == '/')
    {
        execve(args[0], args, env);
        perror("execve");
        ft_free(args);
        exit(127);
    }
    ft_run(args, args[0], env);
    
    ft_free(args);
    exit(127);
}

void ft_second_child(int fd[2], int file2, char *cmd2, char **env)
{
    char **args;

    close(fd[1]);
    
    // Execute command (if empty, exit with status 0)
    if (!cmd2 || cmd2[0] == '\0')
        exit(0);
    
    if (dup2(fd[0], 0) == -1 || dup2(file2, 1) == -1)
    {
        perror("dup2");
        exit(1);
    }
    close(fd[0]);
    close(file2);
    
    args = ft_split(cmd2, ' ');
    if (!args)
        exit(1);
    
    if (args[0] && args[0][0] == '/')
    {
        execve(args[0], args, env);
        perror("execve");
        ft_free(args);
        exit(127);
    }
    ft_run(args, args[0], env);
    
    // This line will only be reached if ft_run fails
    ft_free(args);
    exit(127);
}
