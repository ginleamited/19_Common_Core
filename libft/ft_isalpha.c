int isalpha(int c)
{
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return (1);
    return (0);
}

#include <stdio.h>

int main()
{
    char *str = "salut";  // Define a string to test
    int i = 0;

    while (str[i] != '\0') 
    {
        if (isalpha(str[i]))
            printf("'%c' is alpha\n", str[i]);
        else 
            printf("'%c' is not alpha\n", str[i]);
        i++;
    }    

    return (0);
}