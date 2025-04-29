#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main() {
    int opcion;
    char dni[15], nombre[30], apellido[30];
    Jugador j;

    do {
        printf("\n1. Ingresar persona\n2. Buscar por DNI\n3. Buscar por nombre y apellido\n");
        printf("4. Listar ordenado (1-nombre, 2-DNI)\n5. Hacer backup\n");
        printf("6. Registrar jugador\n7. Top 10 jugadores\n8. Buscar jugador\n9. Salir\n");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: ingresar_datos(); break;
            case 2: printf("DNI: "); scanf("%s", dni); buscar_por_dni(dni); break;
            case 3: printf("Nombre: "); scanf("%s", nombre);
                    printf("Apellido: "); scanf("%s", apellido);
                    buscar_por_nombre_apellido(nombre, apellido); break;
            case 4: printf("Ordenar por (1-nombre, 2-DNI): "); scanf("%d", &opcion);
                    listar_ordenado(opcion); break;
            case 5: copiar_backup(); break;
            case 6: printf("Nombre: "); scanf("%s", j.nombre);
                    printf("Puntaje: "); scanf("%d", &j.puntaje);
                    guardar_jugador(j); break;
            case 7: top_10_jugadores(); break;
            case 8: printf("Nombre del jugador: "); scanf("%s", nombre);
                    buscar_jugador(nombre); break;
        }

    } while (opcion != 9);

    return 0;
}