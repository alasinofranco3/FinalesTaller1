#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//int maquina_estados(char* buffer, int* estado) {
	
//}

int main (int argc, char* argv[]) {

	FILE* file = fopen("x.txt", "r+");

	char byte_leido;
	int leidos = 0;
	int escritos = 0;
	int estado = 0;
	char uno = '1';
	char dos = '2';

	while(fread(&byte_leido,sizeof(char), 1,file)) {
		leidos ++;

		if (estado == 0) {
			if (byte_leido == '1') {
				estado ++;
			}
			fseek(file, escritos, SEEK_SET);
			fwrite(&byte_leido, 1, 1, file);
			fseek(file, leidos, SEEK_SET);
			escritos ++;
		} else if (estado == 1) {
			if (byte_leido == '2') {
				estado ++;
			}
			fseek(file, escritos, SEEK_SET);
			fwrite(&uno, 1, 1, file);
			fwrite(&byte_leido, 1, 1, file);
			fseek(file, leidos, SEEK_SET);
			escritos += 2;
			estado = 0;
		} else if (estado == 2) {
			if (byte_leido == '3') {
				estado ++;
			}
			fseek(file, escritos, SEEK_SET);
			fwrite(&uno, 1, 1, file);
			fwrite(&dos, 1, 1, file);
			fwrite(&byte_leido, 1, 1, file);
			fseek(file, leidos, SEEK_SET);
			escritos += 3;
			estado = 0;
		} else {
			if (byte_leido == '3') {
				continue;
			}
			fseek(file, escritos, SEEK_SET);
			fwrite(&uno, 1, 1, file);
			fwrite(&dos, 1, 1, file);
			fwrite(&byte_leido, 1, 1, file);
			fseek(file, leidos, SEEK_SET);
			escritos += 3;
			estado = 0;
		}

	}

	ftruncate(fileno(file), escritos);

	fclose(file);

	return 0;
}