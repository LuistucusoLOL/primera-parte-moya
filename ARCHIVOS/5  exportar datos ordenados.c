void guardarCopiaOrdenada(FILE *archivoOriginal, int tipoOrden) {
    FILE *archivoNuevo;
    char nombreArchivo[100];
    
    printf("\nIngrese nombre para el nuevo archivo (sin extensión): ");
    fgets(nombreArchivo, 100, stdin);
    nombreArchivo[strcspn(nombreArchivo, "\n")] = 0;
    strcat(nombreArchivo, ".dat");
    
    archivoNuevo = fopen(nombreArchivo, "wb");
    if(archivoNuevo == NULL) {
        printf("Error al crear el nuevo archivo.\n");
        return;
    }
    
    rewind(archivoOriginal);
    Persona p;
    Persona personas[100];
    int count = 0;
    
    // Leer todos los registros
    while(fread(&p, sizeof(Persona), 1, archivoOriginal) && count < 100) {
        personas[count++] = p;
    }
    
    // Ordenar
    if(tipoOrden == 1) {
        qsort(personas, count, sizeof(Persona), compararPorNombreApellido);
    } else {
        qsort(personas, count, sizeof(Persona), compararPorDNI);
    }
    
    // Escribir en el nuevo archivo
    for(int i = 0; i < count; i++) {
        fwrite(&personas[i], sizeof(Persona), 1, archivoNuevo);
    }
    
    fclose(archivoNuevo);
    printf("Archivo '%s' creado correctamente con los datos ordenados.\n", nombreArchivo);
}