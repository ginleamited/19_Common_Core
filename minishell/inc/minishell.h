/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:31:51 by jilin             #+#    #+#             */
/*   Updated: 2025/05/09 01:41:35 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include "../lib/inc/libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>

typedef struct s_command {
    char *cmd;
    char **args;
    char *input_file;
    char *output_file;
    int append;
    int is_heredoc;
    char *heredoc_delim;
    char *heredoc_content;
    struct s_command *next;
} t_command;

// Execution prototypes
int execute(t_command *cmd, char ***env);
int execute_builtin(t_command *cmd, char ***env);
int execute_external(t_command *cmd, char **env);
int execute_pipeline(t_command *cmd, char **env);
void setup_redirections(t_command *cmd);
char **duplicate_env(char **envp);
char *get_env(char *key, char **env);
void set_env(char *keyval, char ***env);
void setup_signals(void);
t_command *mock_parser(int test_case);
void test_mock_parser(void);
void free_command(t_command *cmd);
t_command *parse_input(char *input);
int is_builtin(char *cmd);
char **ft_arraydup(char **arr); // Added for mock_parser.c

// Built-in prototypes
int builtin_cd(char **args, char ***env);
int builtin_exit(char **args);
int builtin_env(char **env);
int builtin_export(char **args, char ***env);
int builtin_unset(char **args, char ***env);
int builtin_pwd(void);
int builtin_echo(char **args);

#endif