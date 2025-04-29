#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    system("color 0a");
    
    char palabras[5][50];
    char subcadena[50] = "";
    char temp[50];
    int max_len = 0;
    
    for(int i = 0; i < 5; i++) {
        printf("Ingrese palabra %d: ", i+1);
        fgets(palabras[i], sizeof(palabras[i]), stdin);
        palabras[i][strcspn(palabras[i], "\n")] = '\0';
    }
    
    for(int len = strlen(palabras[0]); len > 0; len--) {
        for(int pos = 0; pos <= strlen(palabras[0])-len; pos++) {
            strncpy(temp, palabras[0]+pos, len);
            temp[len] = '\0';
            
            int encontrada = 1;
            for(int i = 1; i < 5; i++) {
                if(strstr(palabras[i], temp) == NULL) {
                    encontrada = 0;
                    break;
                }
            }
            
            if(encontrada && len > max_len) {
                max_len = len;
                strcpy(subcadena, temp);
                break;
            }
        }
        if(max_len > 0) break;
    }
    
    printf("La subcadena comun mas larga es: %s\n", subcadena);
}

