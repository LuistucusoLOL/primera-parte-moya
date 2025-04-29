// Función para comparar por nombre y apellido (para qsort)
int compararPorNombreApellido(const void *a, const void *b) {
    Persona *pa = (Persona *)a;
    Persona *pb = (Persona *)b;
    int cmpApellido = strcmp(pa->apellido, pb->apellido);
    if (cmpApellido != 0) return cmpApellido;
    return strcmp(pa->nombre, pb->nombre);
}

// Función para comparar por DNI (para qsort)
int compararPorDNI(const void *a, const void *b) {
    Persona *pa = (Persona *)a;
    Persona *pb = (Persona *)b;
    return strcmp(pa->dni, pb->dni);
}

// Función para mostrar datos ordenados
void mostrarOrdenado(FILE *archivo, int tipoOrden) {
    rewind(archivo);
    Persona p;
    Persona personas[100]; // Asumimos un máximo de 100 registros
    int count = 0;
    
    // Leer todos los registros
    while(fread(&p, sizeof(Persona), 1, archivo) && count < 100) {
        personas[count++] = p;
    }
    
    // Ordenar según el criterio
    if(tipoOrden == 1) {
        qsort(personas, count, sizeof(Persona), compararPorNombreApellido);
        printf("\nDatos ordenados por Nombre y Apellido:\n");
    } else {
        qsort(personas, count, sizeof(Persona), compararPorDNI);
        printf("\nDatos ordenados por DNI:\n");
    }
    
    // Mostrar resultados
    for(int i = 0; i < count; i++) {
        printf("DNI: %s, Nombre: %s, Apellido: %s\n", 
               personas[i].dni, personas[i].nombre, personas[i].apellido);
    }
}

// Agregar opción al menú para ordenar