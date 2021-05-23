#include <stdio.h>

int main(int argc, char const *argv[], char **env)
{
    int i = 0;
    while (env[i] != NULL)
    {
        printf("env[%d]=%s\n", i, env[i]);
        i++;
    }
    return 0;
}
