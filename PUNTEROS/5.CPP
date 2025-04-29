#include <stdio.h>

void concatenar(char *destino, char *origen) {
    while (*destino) destino++;
    while (*origen) {
        *destino = *origen;
        destino++;
        origen++;
    }
    *destino = '\0';
}
int main() {
    char cadena1[100] = "Hola ";
    char cadena2[] = "Mundo";

    concatenar(cadena1, cadena2);
    printf("Cadena concatenada: %s\n", cadena1);

    return 0;
}

