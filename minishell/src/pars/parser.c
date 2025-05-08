#include "../../inc/minishell.h"

// Helper to split input into tokens (simplified, no quote handling)
char **split_tokens(char *input) {
    return ft_split(input, ' '); // Placeholder; real parser should handle quotes
}

// Basic parser to create a single command (no pipes/redirections yet)
t_command *parse_input(char *input) {
    if (!input || !*input)
        return NULL;
    
    char **tokens = split_tokens(input);
    if (!tokens || !tokens[0])
    {
        ft_free_array(tokens);
        return NULL;
    }

    // Create a single command (extend for pipes/redirections)
    t_command *cmd = malloc(sizeof(t_command));
    if (!cmd) {
        ft_free_array(tokens);
        return NULL;
    }
    cmd->cmd = ft_strdup(tokens[0]);
    cmd->args = ft_arraydup(tokens);
    cmd->input_file = NULL;
    cmd->output_file = NULL;
    cmd->append = 0;
    cmd->is_heredoc = 0;
    cmd->heredoc_delim = NULL;
    cmd->heredoc_content = NULL;
    cmd->next = NULL;

    ft_free_array(tokens);
    return cmd;
}