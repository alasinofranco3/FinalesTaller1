#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

int calcular_termino(int numero_termino) {
	if (numero_termino < 2) return 1; 
	else return (3*calcular_termino(numero_termino - 2)) + (2*calcular_termino(numero_termino - 1));
}

int main(int argc, char* argv[]) {
	int termino_inicial = atoi(argv[1]);
	int cant_terminos = atoi(argv[2]);

	if (termino_inicial < 2) return ERROR;

	for (int i = 0; i < cant_terminos; i++) {
		printf("%d\n", calcular_termino(termino_inicial + i));
	}

	return 0;
}
