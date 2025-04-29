#include <stdio.h>

void copiar_arreglo(int *origen, int *destino, int tam) {
    for(int i = 0; i < tam; i++) {
        *(destino + i) = *(origen + i);
    }
}

int main() {
    int origen[] = {1, 2, 3, 4, 5};
    int destino[5];

    copiar_arreglo(origen, destino, 5);

    printf("Arreglo copiado: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", destino[i]);
    }
    printf("\n");

    return 0;
}
