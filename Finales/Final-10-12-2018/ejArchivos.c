#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char* argv[]) {
	FILE* file = fopen("nros2bytes.dat", "rb+");

	int leidos = 0;
	int escritos = 0;
	short int numero;
	int result;

	while (result = fread(&numero, 1,2,file) > 0) {
		leidos += result;
		if (numero % 3 == 0) {
			numero = numero*2;
		}
		fseek(file,escritos,SEEK_SET);
		fwrite(&numero,1,2,file);
		fseek(file,leidos,SEEK_SET);
		escritos += 2;
	}



	fclose(file);
	return 0;
}
