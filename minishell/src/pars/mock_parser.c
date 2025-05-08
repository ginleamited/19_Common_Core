#include "../../inc/minishell.h"

// Helper function to create a new command node
t_command *new_command(char *cmd, char **args, char *input_file, char *output_file, int append, int is_heredoc, char *heredoc_delim, char *heredoc_content) {
    t_command *node = malloc(sizeof(t_command));
    if (!node)
        return NULL;
    node->cmd = cmd ? ft_strdup(cmd) : NULL;
    node->args = args ? ft_arraydup(args) : NULL;
    node->input_file = input_file ? ft_strdup(input_file) : NULL;
    node->output_file = output_file ? ft_strdup(output_file) : NULL;
    node->append = append;
    node->is_heredoc = is_heredoc;
    node->heredoc_delim = heredoc_delim ? ft_strdup(heredoc_delim) : NULL;
    node->heredoc_content = heredoc_content ? ft_strdup(heredoc_content) : NULL;
    node->next = NULL;
    return node;
}

// Helper function to duplicate an array of strings
char **ft_arraydup(char **arr) {
    if (!arr)
        return NULL;
    int i = 0;
    while (arr[i])
        i++;
    char **dup = malloc(sizeof(char *) * (i + 1));
    if (!dup)
        return NULL;
    for (i = 0; arr[i]; i++)
        dup[i] = ft_strdup(arr[i]);
    dup[i] = NULL;
    return dup;
}

// Helper function to free a command structure
void free_command(t_command *cmd) {
    if (!cmd)
        return;
    free_command(cmd->next);
    if (cmd->cmd)
        free(cmd->cmd);
    if (cmd->args)
        ft_free_array(cmd->args);
    if (cmd->input_file)
        free(cmd->input_file);
    if (cmd->output_file)
        free(cmd->output_file);
    if (cmd->heredoc_delim)
        free(cmd->heredoc_delim);
    if (cmd->heredoc_content)
        free(cmd->heredoc_content); // Added
    free(cmd);
}

// Mock parser: Returns a t_command structure for a given test case
t_command *mock_parser(int test_case) {
    t_command *cmd = NULL;
    t_command *next_cmd = NULL;

    if (test_case == 1) { // Simple command: ls -l
        char *args[] = {"ls", "-l", NULL};
        cmd = new_command("ls", args, NULL, NULL, 0, 0, NULL, NULL);
    }
    else if (test_case == 2) { // Built-in: echo -n hello
        char *args[] = {"echo", "-n", "hello", NULL};
        cmd = new_command("echo", args, NULL, NULL, 0, 0, NULL, NULL);
    }
    else if (test_case == 3) { // Redirection: ls -l > out.txt
        char *args[] = {"ls", "-l", NULL};
        cmd = new_command("ls", args, NULL, "out.txt", 0, 0, NULL, NULL);
    }
    else if (test_case == 4) { // Input redirection: cat < in.txt
        char *args[] = {"cat", NULL};
        cmd = new_command("cat", args, "in.txt", NULL, 0, 0, NULL, NULL);
    }
    else if (test_case == 5) { // Append redirection: echo hi >> out.txt
        char *args[] = {"echo", "hi", NULL};
        cmd = new_command("echo", args, NULL, "out.txt", 1, 0, NULL, NULL);
    }
    else if (test_case == 6) { // Heredoc: cat << EOF
        char *args[] = {"cat", NULL};
        cmd = new_command("cat", args, NULL, NULL, 0, 1, "EOF", "Heredoc content\n");
    }
    else if (test_case == 7) { // Pipe: ls -l | grep txt
        char *args1[] = {"ls", "-l", NULL};
        char *args2[] = {"grep", "txt", NULL};
        cmd = new_command("ls", args1, NULL, NULL, 0, 0, NULL, NULL);
        next_cmd = new_command("grep", args2, NULL, NULL, 0, 0, NULL, NULL);
        cmd->next = next_cmd;
    }
    else if (test_case == 8) { // Complex: cat < in.txt | wc -l > out.txt
        char *args1[] = {"cat", NULL};
        char *args2[] = {"wc", "-l", NULL};
        cmd = new_command("cat", args1, "in.txt", NULL, 0, 0, NULL, NULL);
        next_cmd = new_command("wc", args2, NULL, "out.txt", 0, 0, NULL, NULL);
        cmd->next = next_cmd;
    }

    return cmd;
}

// Test function to demonstrate usage
void test_mock_parser(void) {
    char **env = duplicate_env(environ);
    for (int i = 1; i <= 8; i++) {
        printf("Test case %d:\n", i);
        t_command *cmd = mock_parser(i);
        if (cmd) {
            execute(cmd, &env);
            free_command(cmd);
        }
    }
    ft_free_array(env);
}