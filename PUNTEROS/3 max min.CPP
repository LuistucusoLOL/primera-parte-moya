#include <stdio.h>

void mayor_menor(int *arr, int tam, int *mayor, int *menor) {
    *mayor = *arr;
    *menor = *arr;
    for(int i = 1; i < tam; i++) {
        if (*(arr + i) > *mayor) *mayor = *(arr + i);
        if (*(arr + i) < *menor) *menor = *(arr + i);
    }
}

int main() {
    int arreglo[] = {12, 45, 7, 89, 23};
    int mayor, menor;

    mayor_menor(arreglo, 5, &mayor, &menor);
    printf("Mayor: %d, Menor: %d\n", mayor, menor);

    return 0;
}
