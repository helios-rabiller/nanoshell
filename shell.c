#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TAILLE_BUFF 1024   // DEFINIR LA TAILLE MAX D'UNE COMMANDE
#define TAILLE_ARGS 64    // DEFINIR LE NOMBRE MAX D'ARGUMENTS PAR COMMANDE

int main(void) {
    char input[TAILLE_BUFF];
    char *args[TAILLE_ARGS];
    
    while (1) {
        printf("$ "); //prompt
        
        if (fgets(input, TAILLE_BUFF, stdin) == NULL) {    //si pas d'entrée, quitter(sortir de la boucle)
            break;  
        }
        
        input[strcspn(input, "\n")] = 0;  //enlever le saut de ligne pour les commandes
        
        if (strlen(input) == 0) {  //si entrée vide on va à la prochaine itération  
            continue;
        }
        
                                                             // Tokenisation
        int i = 0;                                          //strtok découpe la chaine en ayant choisi
        args[i] = strtok(input, " ");                      // un délimiteur qui est ici un espace 
        while (args[i] != NULL && i < TAILLE_ARGS - 1) {  // strtok renvoie NULL quand il n'y a 
               args[++i] = strtok(NULL, " ");            // plus de token
        }
        
        // LES COMMANDES
        if (strcmp(args[0], "exit") == 0) {   //si la commande est exit on quitte le shell
            break;
        }
        else if (strcmp(args[0], "cd") == 0) {        // Prends args[1] qui est ce qui suit cd donc 
            if (args[1] != NULL) {                    // par exemple /tmp, chdir va changer le
                if (chdir(args[1]) != 0) {           // répertoire courant vers la destination
                    perror("cd");                    // args[1] donc /tmp
                }
            }
        }
        else if (strcmp(args[0], "pwd") == 0) {         // cwd sert à stocker le chemin
            char cwd[TAILLE_BUFF];                     // getcwd interroge le systeme et va
            if (getcwd(cwd, sizeof(cwd)) != NULL) {   // stocker le chemin courant dans cwd
                printf("%s\n", cwd);                 //  cwd = ['/','t','m','p','\0']      
            } else {
                perror("pwd");
            }
        }
        else if (strcmp(args[0], "env") == 0) {  
            extern char **environ; //variable globale + pointeur vers tableau de strings
            for (char **env = environ; *env != NULL; env++) {  //char **env = pointeur vers tableau 
                printf("%s\n", *env);                         // si *env != NULL on affiche la string
            }                                                // exemple: env = ["PATH=/usr/bin:/bin"]
        }
        else {
            printf("%s: commande non reconnue\n", args[0]);  // si la commande ne correspond à rien
        }                                                   //  on affiche ça
    }
    
    return 0;
}