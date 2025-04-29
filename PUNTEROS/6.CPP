#include <stdio.h>

int contar_ocurrencias(int *arr, int tam, int valor) {
    int contador = 0;
    for (int i = 0; i < tam; i++) {
        if (*(arr + i) == valor) {
            contador++;
        }
    }
    return contador;
}

int main() {
    int arreglo[] = {3, 7, 3, 2, 3, 7, 8};
    int valor = 3;
    int ocurrencias = contar_ocurrencias(arreglo, 7, valor);

    printf("El valor %d aparece %d veces.\n", valor, ocurrencias);

    return 0;
}
