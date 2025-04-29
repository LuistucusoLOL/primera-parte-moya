// Agregar esta función al código anterior
void buscarPorNombreApellido(FILE *archivo) {
    Persona p;
    char nombreBusqueda[50];
    char apellidoBusqueda[50];
    int encontrado = 0;
    
    printf("\nIngrese nombre a buscar: ");
    fgets(nombreBusqueda, 50, stdin);
    nombreBusqueda[strcspn(nombreBusqueda, "\n")] = 0;
    
    printf("Ingrese apellido a buscar: ");
    fgets(apellidoBusqueda, 50, stdin);
    apellidoBusqueda[strcspn(apellidoBusqueda, "\n")] = 0;
    
    rewind(archivo);
    
    printf("\nResultados de la búsqueda:\n");
    while(fread(&p, sizeof(Persona), 1, archivo)) {
        if(strcmp(p.nombre, nombreBusqueda) == 0 && strcmp(p.apellido, apellidoBusqueda) == 0) {
            printf("DNI: %s, Nombre: %s, Apellido: %s\n", p.dni, p.nombre, p.apellido);
            encontrado = 1;
        }
    }
    
    if(!encontrado) {
        printf("No se encontraron registros con ese nombre y apellido.\n");
    }
}

// Modificar el menú para incluir esta opción
void mostrarMenu() {
    printf("\nMENÚ PRINCIPAL\n");
    printf("1. Ingresar datos\n");
    printf("2. Buscar por DNI\n");
    printf("3. Buscar por Nombre y Apellido\n");
    printf("4. Salir\n");
    printf("Seleccione una opción: ");
}

// Y actualizar el switch en main para manejar la nueva opción