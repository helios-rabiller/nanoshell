#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(void) {
    char input[BUFFER_SIZE]; 
    printf("cmd$ ");
    
    while (fgets(input, BUFFER_SIZE, stdin)) {
        input[strcspn(input, "\n")] = 0;
        
        if (strlen(input) == 0) {
            printf("cmd$ ");
            continue;
        }

        if (strcmp(input, "exit") == 0) {
            printf(" fin du shell suite a l'execution de la commande : %s\n", input);
            break;
        }
        
        
        printf("test pour le retour d'input: %s\n", input);
        
        printf("cmd$ ");
    }
    
    return 0;
}
