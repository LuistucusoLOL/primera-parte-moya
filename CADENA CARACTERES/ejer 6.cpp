#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    system("color 0a");
    
    char cadena[200], invertida[200] = "";
    char *palabra;
    
    printf("Ingrese una cadena: ");
    fgets(cadena, sizeof(cadena), stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
    
    palabra = strtok(cadena, " ");
    while(palabra != NULL) {
        if(strlen(invertida)){
            sprintf(invertida, "%s %s", palabra, invertida);
        } else {
            strcpy(invertida, palabra);
        }
        palabra = strtok(NULL, " ");
    }
    
    printf("Cadena invertida: %s\n", invertida);

}

