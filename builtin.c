#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (void) {
int builtin(char **args) {
    if (strcmp(args[0], "cd") == 0) {
        if (strcmp(args[1], "..") == 0) {
            chdir("..");
            return 0;
        }
        else if (strcmp(args[1], "~") == 0) {
            chdir(getenv("HOME"));
            return 0;
        }
        else if (args[1] != NULL && *args[1] != '\0') {
            chdir(args[1]);
            return 0;
        }
    }
    return 0;
}  

builtin("cd");
}