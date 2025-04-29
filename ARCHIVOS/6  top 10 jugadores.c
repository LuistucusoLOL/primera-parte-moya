#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nombre[50];
    int puntaje;
} Jugador;

void ingresarJugador(FILE *archivo);
void mostrarTop10(FILE *archivo);
void buscarJugador(FILE *archivo);
int compararPuntajes(const void *a, const void *b);

int main() {
    FILE *archivo;
    int opcion;
    
    archivo = fopen("puntajes.dat", "a+");
    if(archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }
    
    do {
        printf("\nMENÚ DE JUGADORES\n");
        printf("1. Ingresar nuevo jugador\n");
        printf("2. Mostrar top 10 jugadores\n");
        printf("3. Buscar jugador por nombre\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer
        
        switch(opcion) {
            case 1:
                ingresarJugador(archivo);
                break;
            case 2:
                mostrarTop10(archivo);
                break;
            case 3:
                buscarJugador(archivo);
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while(opcion != 4);
    
    fclose(archivo);
    return 0;
}

void ingresarJugador(FILE *archivo) {
    Jugador j;
    
    printf("\nIngrese nombre del jugador: ");
    fgets(j.nombre, 50, stdin);
    j.nombre[strcspn(j.nombre, "\n")] = 0;
    
    printf("Ingrese puntaje: ");
    scanf("%d", &j.puntaje);
    getchar(); // Limpiar buffer
    
    fwrite(&j, sizeof(Jugador), 1, archivo);
    printf("Jugador registrado correctamente.\n");
}

int compararPuntajes(const void *a, const void *b) {
    Jugador *ja = (Jugador *)a;
    Jugador *jb = (Jugador *)b;
    return jb->puntaje - ja->puntaje; // Orden descendente
}

void mostrarTop10(FILE *archivo) {
    rewind(archivo);
    Jugador j;
    Jugador jugadores[100];
    int count = 0;
    
    // Leer todos los jugadores
    while(fread(&j, sizeof(Jugador), 1, archivo) && count < 100) {
        jugadores[count++] = j;
    }
    
    // Ordenar por puntaje
    qsort(jugadores, count, sizeof(Jugador), compararPuntajes);
    
    // Mostrar top 10
    printf("\nTOP 10 JUGADORES\n");
    int max = (count < 10) ? count : 10;
    for(int i = 0; i < max; i++) {
        printf("%d. %s - %d puntos\n", i+1, jugadores[i].nombre, jugadores[i].puntaje);
    }
}

void buscarJugador(FILE *archivo) {
    char nombreBusqueda[50];
    Jugador j;
    int encontrado = 0;
    
    printf("\nIngrese nombre a buscar: ");
    fgets(nombreBusqueda, 50, stdin);
    nombreBusqueda[strcspn(nombreBusqueda, "\n")] = 0;
    
    rewind(archivo);
    
    printf("\nResultados de la búsqueda:\n");
    while(fread(&j, sizeof(Jugador), 1, archivo)) {
        if(strcmp(j.nombre, nombreBusqueda) == 0) {
            printf("Nombre: %s, Puntaje: %d\n", j.nombre, j.puntaje);
            encontrado = 1;
        }
    }
    
    if(!encontrado) {
        printf("No se encontraron jugadores con ese nombre.\n");
    }
}