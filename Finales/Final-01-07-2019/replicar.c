#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


char* replicar (char* cadena, int l1, int l2, int q) {
	int char_a_duplicar = l2 - l1 + 1;
	int tamanio_adicional_cadena = char_a_duplicar * (q - 1);
	int tam_result = strlen(cadena) + tamanio_adicional_cadena;

	char* result = malloc(sizeof(char)*tam_result);

	memcpy(result,cadena,l1);
	
	for (int i = 0; i < char_a_duplicar *q ; i+=char_a_duplicar) {
		for (int j = l1; j <= l2 ; j++) {
			result[j+i] = cadena[j];
		}
	}

	int var = l1 + char_a_duplicar + tamanio_adicional_cadena;
	
	memcpy(&result[var],&cadena[l2 + 1], strlen(cadena) - (l2+1));

	return result;

}

int main () {
	char* result = replicar("hola",1,2,3);
	printf("%s\n", result);
	free(result);
	return 0;
}

