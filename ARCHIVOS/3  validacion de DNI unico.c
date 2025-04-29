// Función para verificar si un DNI ya existe
int dniExiste(FILE *archivo, const char *dni) {
    Persona p;
    rewind(archivo);
    
    while(fread(&p, sizeof(Persona), 1, archivo)) {
        if(strcmp(p.dni, dni) == 0) {
            return 1; // Existe
        }
    }
    return 0; // No existe
}

// Modificar la función ingresarDatos para validar
void ingresarDatos(FILE *archivo) {
    Persona p;
    
    printf("\nIngrese nombre: ");
    fgets(p.nombre, 50, stdin);
    p.nombre[strcspn(p.nombre, "\n")] = 0;
    
    printf("Ingrese apellido: ");
    fgets(p.apellido, 50, stdin);
    p.apellido[strcspn(p.apellido, "\n")] = 0;
    
    do {
        printf("Ingrese DNI: ");
        fgets(p.dni, 20, stdin);
        p.dni[strcspn(p.dni, "\n")] = 0;
        
        if(dniExiste(archivo, p.dni)) {
            printf("Error: Este DNI ya está registrado. Ingrese otro.\n");
        }
    } while(dniExiste(archivo, p.dni));
    
    fwrite(&p, sizeof(Persona), 1, archivo);
    printf("Datos guardados correctamente.\n");
}