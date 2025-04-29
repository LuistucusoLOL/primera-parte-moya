#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nombre[50];
    char apellido[50];
    char dni[20];
} Persona;

void ingresarDatos(FILE *archivo);
void buscarPorDNI(FILE *archivo);
void mostrarMenu();

int main() {
    FILE *archivo;
    int opcion;
    
    archivo = fopen("registros.dat", "a+");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }
    
    do {
        mostrarMenu();
        scanf("%d", &opcion);
        getchar(); // Limpiar el buffer
        
        switch(opcion) {
            case 1:
                ingresarDatos(archivo);
                break;
            case 2:
                buscarPorDNI(archivo);
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while(opcion != 3);
    
    fclose(archivo);
    return 0;
}

void mostrarMenu() {
    printf("\nMENÚ PRINCIPAL\n");
    printf("1. Ingresar datos\n");
    printf("2. Buscar por DNI\n");
    printf("3. Salir\n");
    printf("Seleccione una opción: ");
}

void ingresarDatos(FILE *archivo) {
    Persona p;
    
    printf("\nIngrese nombre: ");
    fgets(p.nombre, 50, stdin);
    p.nombre[strcspn(p.nombre, "\n")] = 0; // Eliminar salto de línea
    
    printf("Ingrese apellido: ");
    fgets(p.apellido, 50, stdin);
    p.apellido[strcspn(p.apellido, "\n")] = 0;
    
    printf("Ingrese DNI: ");
    fgets(p.dni, 20, stdin);
    p.dni[strcspn(p.dni, "\n")] = 0;
    
    fwrite(&p, sizeof(Persona), 1, archivo);
    printf("Datos guardados correctamente.\n");
}

void buscarPorDNI(FILE *archivo) {
    Persona p;
    char dniBusqueda[20];
    int encontrado = 0;
    
    printf("\nIngrese DNI a buscar: ");
    fgets(dniBusqueda, 20, stdin);
    dniBusqueda[strcspn(dniBusqueda, "\n")] = 0;
    
    rewind(archivo); // Volver al inicio del archivo
    
    while(fread(&p, sizeof(Persona), 1, archivo)) {
        if(strcmp(p.dni, dniBusqueda) == 0) {
            printf("\nDatos encontrados:\n");
            printf("Nombre: %s\n", p.nombre);
            printf("Apellido: %s\n", p.apellido);
            encontrado = 1;
            break;
        }
    }
    
    if(!encontrado) {
        printf("No se encontraron registros con ese DNI.\n");
    }
}