#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int builtin(char **args)
{
    if (args == NULL || args[0] == NULL)
        return 0;

    if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            chdir(getenv("HOME"));
        }
        else if (strcmp(args[1], "..") == 0) {
            chdir("..");
        }
        else {
            if (chdir(args[1]) != 0)
                perror("cd");
        }
        return 0;
    }
    return 0;
}

int main(void)
{
    char *cmd1[] = {"cd", "..", NULL};

    builtin(cmd1);

    return 0;
}
