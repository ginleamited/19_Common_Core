#include "../../inc/minishell.h"
#include <string.h>

extern char **environ; // Added for environ access

t_command *new_command(char *cmd, char **args, char *input_file, char *output_file, int append, char *heredoc_delim) {
    t_command *node = malloc(sizeof(t_command));
    if (!node)
        return NULL;
    node->cmd = cmd ? ft_strdup(cmd) : NULL;
    node->args = args ? ft_arraydup(args) : NULL;
    node->input_file = input_file ? ft_strdup(input_file) : NULL;
    node->output_file = output_file ? ft_strdup(output_file) : NULL;
    node->append = append;
    node->is_heredoc = heredoc_delim ? 1 : 0;
    node->heredoc_delim = heredoc_delim ? ft_strdup(heredoc_delim) : NULL;
    node->heredoc_content = NULL;
    node->next = NULL;
    return node;
}

char **ft_arraydup(char **arr) {
    if (!arr)
        return NULL;
    int len = 0;
    while (arr[len])
        len++;
    char **dup = malloc(sizeof(char *) * (len + 1));
    if (!dup)
        return NULL;
    for (int i = 0; i < len; i++)
        dup[i] = ft_strdup(arr[i]);
    dup[len] = NULL;
    return dup;
}

void free_command(t_command *cmd) {
    if (!cmd)
        return;
    free(cmd->cmd);
    ft_free_array(cmd->args);
    free(cmd->input_file);
    free(cmd->output_file);
    free(cmd->heredoc_delim);
    free(cmd->heredoc_content);
    t_command *next;
    while (cmd) {
        next = cmd->next;
        free(cmd);
        cmd = next;
    }
}

t_command *mock_parser(int test_case) {
    char *cmd;
    char **args;
    t_command *node, *head, *prev;

    switch (test_case) {
        case 1: // Simple command: ls -l
            cmd = ft_strdup("ls");
            args = malloc(sizeof(char *) * 3);
            args[0] = ft_strdup("ls");
            args[1] = ft_strdup("-l");
            args[2] = NULL;
            return new_command(cmd, args, NULL, NULL, 0, NULL);

        case 2: // Pipeline: ls | grep txt
            head = new_command(ft_strdup("ls"), (char *[]){"ls", NULL}, NULL, NULL, 0, NULL);
            node = new_command(ft_strdup("grep"), (char *[]){"grep", "txt", NULL}, NULL, NULL, 0, NULL);
            head->next = node;
            return head;

        case 3: // Redirection: cat < input.txt > output.txt
            return new_command(ft_strdup("cat"), (char *[]){"cat", NULL}, "input.txt", "output.txt", 0, NULL);

        case 4: // Append redirection: echo hello >> output.txt
            return new_command(ft_strdup("echo"), (char *[]){"echo", "hello", NULL}, NULL, "output.txt", 1, NULL);

        case 5: // Heredoc: cat << EOF
            return new_command(ft_strdup("cat"), (char *[]){"cat", NULL}, NULL, NULL, 0, "EOF");

        case 6: // Complex pipeline: ls -l | grep txt | wc -l
            head = new_command(ft_strdup("ls"), (char *[]){"ls", "-l", NULL}, NULL, NULL, 0, NULL);
            prev = head;
            node = new_command(ft_strdup("grep"), (char *[]){"grep", "txt", NULL}, NULL, NULL, 0, NULL);
            prev->next = node;
            prev = node;
            node = new_command(ft_strdup("wc"), (char *[]){"wc", "-l", NULL}, NULL, NULL, 0, NULL);
            prev->next = node;
            return head;

        default:
            return NULL;
    }
}

void test_mock_parser(void) {
    char **env = duplicate_env(environ);
    for (int i = 1; i <= 6; i++) {
        printf("Test case %d:\n", i);
        t_command *cmd = mock_parser(i);
        if (cmd) {
            printf("Command: %s\n", cmd->cmd ? cmd->cmd : "(null)");
            if (cmd->args) {
                printf("Args: ");
                for (int j = 0; cmd->args[j]; j++)
                    printf("%s ", cmd->args[j]);
                printf("\n");
            }
            if (cmd->input_file)
                printf("Input file: %s\n", cmd->input_file);
            if (cmd->output_file)
                printf("Output file: %s\n", cmd->output_file);
            if (cmd->append)
                printf("Append mode: yes\n");
            if (cmd->is_heredoc)
                printf("Heredoc delimiter: %s\n", cmd->heredoc_delim);
            t_command *tmp = cmd->next;
            while (tmp) {
                printf("Next command: %s\n", tmp->cmd ? tmp->cmd : "(null)");
                if (tmp->args) {
                    printf("Args: ");
                    for (int j = 0; tmp->args[j]; j++)
                        printf("%s ", tmp->args[j]);
                    printf("\n");
                }
                tmp = tmp->next;
            }
            execute(cmd, &env);
            free_command(cmd);
        } else {
            printf("No command returned\n");
        }
        printf("\n");
    }
    ft_free_array(env);
}