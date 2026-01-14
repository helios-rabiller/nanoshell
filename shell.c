#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define TAILLE_BUFF 1024 //taille du buffer
#define TAILLE_ARGS 64 //taille du tableau arg

int main(void) {
    char input[TAILLE_BUFF];
    char *args[TAILLE_ARGS];
    int i;
    pid_t pid;
    
    printf("$ ");
    
    while (fgets(input, TAILLE_BUFF, stdin)) {
        // suppression du \n
        input[strcspn(input, "\n")] = 0;
        
        //si y a rien on reprompt
        if (strlen(input) == 0) {
            printf("$ ");
            continue;
        }
        
        //Tokenisation 
        i = 0;
        char *token = strtok(input, " ");
        while (token != NULL && i < TAILLE_ARGS - 1) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;
        
        //si les deux chaines sont similaire on exit
        if (strcmp(args[0], "exit") == 0) {
            break;
        }
        
        // si arg[0] est = à cd 
        if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                fprintf(stderr, "cd: argument manquant\n");
            } else if (chdir(args[1]) != 0) {
                perror("cd");
            }
            printf("$ ");
            continue;
        }

        /* Fork + exec
        pid = fork();
        if (pid < 0) {
            perror("fork");
        } else if (pid == 0) {
            // Enfant
            execvp(args[0], args);
            //execvp a échoué
            fprintf(stderr, "%s: commande introuvable\n", args[0]);
            break;
        } else {
            // Parent
            wait(NULL);
        }*/
        
        printf("$ ");
    }
    
    return 0;
}