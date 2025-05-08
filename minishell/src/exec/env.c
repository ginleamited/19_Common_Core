#include "../../inc/minishell.h"

char **duplicate_env(char **envp) {
	int i = 0;
	while (envp[i])
		i++;
	char **env = malloc(sizeof(char *) * (i + 1));
	if (!env)
		return NULL;
	for (i = 0; envp[i]; i++)
		env[i] = ft_strdup(envp[i]);
	env[i] = NULL;
	return env;
}

char *get_env(char *key, char **env) {
    int i = 0;
    int key_len = ft_strlen(key);
    while (env[i]) {
        if (ft_strncmp(env[i], key, key_len) == 0 && env[i][key_len] == '=')
            return env[i] + key_len + 1;
        i++;
    }
    return NULL;
}