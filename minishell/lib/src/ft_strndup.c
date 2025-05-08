#include "../inc/libft.h"

char *ft_strndup(const char *s, size_t n) {
    char *dup = malloc(n + 1);
    if (!dup)
        return NULL;
    ft_strlcpy(dup, s, n + 1);
    return dup;
}