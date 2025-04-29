#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    system("color 0a");
    
    char palabra1[50], palabra2[50];
    int contador[256] = {0};
    int esAnagrama = 1;
    
    printf("Ingrese primera palabra: ");
    fgets(palabra1, sizeof(palabra1), stdin);
    palabra1[strcspn(palabra1, "\n")] = '\0';
    
    printf("Ingrese segunda palabra: ");
    fgets(palabra2, sizeof(palabra2), stdin);
    palabra2[strcspn(palabra2, "\n")] = '\0';
    
    if(strlen(palabra1) != strlen(palabra2)) {
        esAnagrama = 0;
    } else {
        for(int i = 0; i < strlen(palabra1); i++) {
            contador[(int)palabra1[i]]++;
            contador[(int)palabra2[i]]--;
        }
        
        for(int i = 0; i < 256; i++) {
            if(contador[i] != 0) {
                esAnagrama = 0;
                break;
            }
        }
    }
    
    printf("Las palabras %s %s anagramas\n", esAnagrama);
}

