#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int existe_dni(const char *dni) {
    FILE *f = fopen(FILENAME, "r");
    Persona p;
    while (f && fread(&p, sizeof(Persona), 1, f)) {
        if (strcmp(p.dni, dni) == 0) {
            fclose(f);
            return 1;
        }
    }
    if (f) fclose(f);
    return 0;
}

void guardar_persona(Persona p) {
    FILE *f = fopen(FILENAME, "a");
    fwrite(&p, sizeof(Persona), 1, f);
    fclose(f);
}

void ingresar_datos() {
    Persona p;
    printf("Ingrese Nombre: ");
    scanf("%s", p.nombre);
    printf("Ingrese Apellido: ");
    scanf("%s", p.apellido);
    printf("Ingrese DNI: ");
    scanf("%s", p.dni);

    if (existe_dni(p.dni)) {
        printf("ERROR: El DNI ya existe.\n");
        return;
    }

    guardar_persona(p);
    printf("Datos guardados correctamente.\n");
}

void buscar_por_dni(const char *dni) {
    FILE *f = fopen(FILENAME, "r");
    Persona p;
    int encontrado = 0;

    while (f && fread(&p, sizeof(Persona), 1, f)) {
        if (strcmp(p.dni, dni) == 0) {
            printf("Nombre: %s, Apellido: %s\n", p.nombre, p.apellido);
            encontrado = 1;
            break;
        }
    }
    if (f) fclose(f);
    if (!encontrado) printf("DNI no encontrado.\n");
}

void buscar_por_nombre_apellido(const char *nombre, const char *apellido) {
    FILE *f = fopen(FILENAME, "r");
    Persona p;
    int encontrado = 0;

    while (f && fread(&p, sizeof(Persona), 1, f)) {
        if (strcmp(p.nombre, nombre) == 0 && strcmp(p.apellido, apellido) == 0) {
            printf("DNI: %s\n", p.dni);
            encontrado = 1;
        }
    }
    if (f) fclose(f);
    if (!encontrado) printf("Persona no encontrada.\n");
}

int comparar_nombre(const void *a, const void *b) {
    return strcmp(((Persona*)a)->nombre, ((Persona*)b)->nombre);
}

int comparar_dni(const void *a, const void *b) {
    return strcmp(((Persona*)a)->dni, ((Persona*)b)->dni);
}

void listar_ordenado(int modo) {
    Persona arr[MAX];
    int n = 0;
    FILE *f = fopen(FILENAME, "r");

    while (f && fread(&arr[n], sizeof(Persona), 1, f)) n++;
    if (f) fclose(f);

    qsort(arr, n, sizeof(Persona), modo == 1 ? comparar_nombre : comparar_dni);

    for (int i = 0; i < n; i++) {
        printf("%s %s - DNI: %s\n", arr[i].nombre, arr[i].apellido, arr[i].dni);
    }
}

void copiar_backup() {
    FILE *orig = fopen(FILENAME, "r");
    FILE *dest = fopen(BACKUP_FILENAME, "w");

    Persona p;
    while (orig && fread(&p, sizeof(Persona), 1, orig)) {
        fwrite(&p, sizeof(Persona), 1, dest);
    }

    if (orig) fclose(orig);
    if (dest) fclose(dest);
    printf("Backup realizado exitosamente.\n");
}

int comparar_puntaje(const void *a, const void *b) {
    return ((Jugador*)b)->puntaje - ((Jugador*)a)->puntaje;
}

void guardar_jugador(Jugador j) {
    FILE *f = fopen(JUGADORES_FILENAME, "a");
    fwrite(&j, sizeof(Jugador), 1, f);
    fclose(f);
}

void top_10_jugadores() {
    Jugador arr[MAX];
    int n = 0;
    FILE *f = fopen(JUGADORES_FILENAME, "r");
    while (f && fread(&arr[n], sizeof(Jugador), 1, f)) n++;
    if (f) fclose(f);

    qsort(arr, n, sizeof(Jugador), comparar_puntaje);

    for (int i = 0; i < n && i < 10; i++) {
        printf("%s - %d\n", arr[i].nombre, arr[i].puntaje);
    }
}

void buscar_jugador(const char *nombre) {
    FILE *f = fopen(JUGADORES_FILENAME, "r");
    Jugador j;
    int encontrado = 0;

    while (f && fread(&j, sizeof(Jugador), 1, f)) {
        if (strcmp(j.nombre, nombre) == 0) {
            printf("Nombre: %s, Puntaje: %d\n", j.nombre, j.puntaje);
            encontrado = 1;
        }
    }
    if (f) fclose(f);
    if (!encontrado) printf("Jugador no encontrado.\n");
}