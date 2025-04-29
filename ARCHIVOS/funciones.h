#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX 100
#define FILENAME "datos.txt"
#define BACKUP_FILENAME "datos_backup.txt"
#define JUGADORES_FILENAME "jugadores.txt"

typedef struct {
    char nombre[30];
    char apellido[30];
    char dni[15];
} Persona;

typedef struct {
    char nombre[30];
    int puntaje;
} Jugador;

int existe_dni(const char *dni);
void guardar_persona(Persona p);
void listar_ordenado(int modo);
void buscar_por_dni(const char *dni);
void buscar_por_nombre_apellido(const char *nombre, const char *apellido);
void copiar_backup();
void ingresar_datos();
void guardar_jugador(Jugador j);
void top_10_jugadores();
void buscar_jugador(const char *nombre);

#endif