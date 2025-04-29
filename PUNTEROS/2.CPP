#include <stdio.h>

void suma_promedio(int *arr, int tam, int *suma, float *prom) {
    *suma = 0;
    for(int i = 0; i < tam; i++) {
        *suma += *(arr + i);
    }
    *prom = (float)(*suma) / tam;
}

int main() {
    int arreglo[] = {10, 20, 30, 40, 50};
    int suma;
    float promedio;

    suma_promedio(arreglo, 5, &suma, &promedio);
    printf("Suma: %d, Promedio: %.2f\n", suma, promedio);

    return 0;
}
