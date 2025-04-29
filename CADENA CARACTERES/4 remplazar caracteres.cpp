#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    system("color 0a");
    
    char cadena[100], original, reemplazo;
    
    printf("Ingrese una cadena: ");
    fgets(cadena, sizeof(cadena), stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
    
    printf("Ingrese el caracter a reemplazar: ");
    original = getchar();
    getchar();
    
    printf("Ingrese el caracter de reemplazo: ");
    reemplazo = getchar();
    
    for(int i = 0; i < strlen(cadena); i++) {
        if(cadena[i] == original) {
            cadena[i] = reemplazo;
        }
    }
    
    printf("Cadena modificada: %s\n", cadena);
}

