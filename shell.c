#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024 // define char user input

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
            break;
        }
        
        
        printf("Vous avez saisi: %s\n", input);
        
        printf("cmd$ ");
    }
    
    return 0;
}