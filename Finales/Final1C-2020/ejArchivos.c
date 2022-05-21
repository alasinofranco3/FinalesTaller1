/* Escribir un programa en ISO C que procese el archivo nros1byte.dat sobre si mismo ,eliminando
los bytes multiplos de 6*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int ftruncate(int fd, off_t length);

int main() {
	FILE* file = fopen("nros1byte.dat", "rb+");

	//char buffer [1];
	unsigned short int numero;
	int bytes_escritos = 0;
	int bytes_leidos = 0;

	while (fread(&numero, 1, 1, file) == 1) {
		bytes_leidos ++;
		
		if ((numero % 6) != 0) {
			fseek(file, bytes_escritos, SEEK_SET);
			fwrite(&numero, 1, 1, file);
			bytes_escritos ++;
			fseek(file, bytes_leidos, SEEK_SET);	
		}
	}

	ftruncate(fileno(file), bytes_escritos);

	fclose(file);
}