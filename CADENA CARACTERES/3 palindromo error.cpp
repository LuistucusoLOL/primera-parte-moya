#include <stdio.h>
#include <string.h>
#include <stdlib.h>

main(){
	system("color 0a");
	const char *palabra;
    int inicio = 0;
    int fin = strlen(palabra) - 1;
    int pali;
    
    while (fin > inicio) {
       
        if (palabra[inicio] != palabra[fin]) {
            pali=0;
            break;
        }
        inicio++;
        fin--;
    }
    pali=1;
    
    printf("ingrese una palabra\n");
	scanf("%s", palabra);
	
	if(pali == 1){
		printf("la palabra %s es un palindromo\n", palabra);	
	}
	else{
		printf("la palabra %s no es un palindromo\n", palabra);
	}
}

