#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    system("color 0a");
    
    int contVocales = 0;
    char palabra[40];
    
    printf("Ingrese una palabra: ");
    fgets(palabra, sizeof(palabra), stdin);
    palabra[strcspn(palabra, "\n")] = '\0';
    
    for(int i = 0; i < strlen(palabra); i++) {
        if( palabra[i] == 'a' || palabra[i] == 'e' || palabra[i] == 'i' || palabra[i] == 'o' || palabra[i] == 'u' || palabra[i] == 'A' || palabra[i] == 'E' || palabra[i] == 'I' || palabra[i] == 'O' || palabra[i] == 'U' || palabra[i] == 'á' || palabra[i] == 'é' || palabra[i] == 'í' || palabra[i] == 'ó' || palabra[i] == 'ú' || palabra[i] == 'Á' || palabra[i] == 'É' || palabra[i] == 'Í' || palabra[i] == 'Ó' || palabra[i] == 'Ú') {
            contVocales++;
        }
    }
    
    printf("La palabra %s tiene un total de %d vocales\n", palabra, contVocales);
}

