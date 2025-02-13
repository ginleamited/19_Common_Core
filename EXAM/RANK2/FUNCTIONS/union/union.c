#include <unistd.h>

int main(int ac, char **av)
{
    // create a lookup table for all chars in ascii table
    int i = 0, lookup[256 = {0};
    
    if (ac == 3)
    {
        // loop over the whole first string
        // for each character, switch the value in
        // the lookup table
        while(av[1][i])
        	lookup[(int)av[1][i++]] = 1;
        i = 0;
        // do the same thing for the second string
        while(av[2][i])
        	lookup[(int)av[2][i++]] = 1;
        i = 0;
        
        // loop over the first string to write the
        // seen chars to the screen, switch back the
        // value in the lookup table once printed
        while (av[1][i])
        {
            if (lookup[(int)av[1][i]])
            {
                write(1, &av[1][i], 1);
                lookup[(int)av[1][i]] = 0;
            }
            i++;
        }
        i = 0;
        while (av[2][i])
        {
            if (lookup[(int)av[2][i]])
            {
                write(1, &av[2][i], 1);
                lookup[(int)av[2][i]] = 0;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}