#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    system("color 0a");
	int cont_palabras=0;
	char cadena[200];
	
	printf("ingrese una serie de palabras\n");
	fgets(cadena,sizeof(cadena),stdin);
	cadena[strcspn(cadena, "\n")]= '\0';
	
	for(int i = 0; i < strlen(cadena); i++){
		if(cadena[i] == ' ' && cadena[i+1] != ' ' && cadena[i+1] != '\0'){
			cont_palabras++;
		}
	}
	if(strlen(cadena)>0){
			cont_palabras++;
		}
	printf("la cantidad de palabras es %d", cont_palabras);
	
}
