#include "../../inc/minishell.h"

int execute(t_command *cmd, char ***env) {
    if (!cmd)
        return 0;
    if (cmd->next)
        return execute_pipeline(cmd, *env);
    if (is_builtin(cmd->cmd))
        return execute_builtin(cmd, env);
    return execute_external(cmd, *env);
}