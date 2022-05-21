#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT_BYTES 2

bool soy_big_endian() {
	uint16 number = 1;  
	uint8  byte = number;

	if (byte == 1) return true;
	return false;

}

int main (int argc, char* argv[]) {
	FILE* wrptr = fopen(argv[1], "rb+");
	FILE* rdptr = fopen(argv[1], "rb");

	char buffer[CANT_BYTES];
	int leidos;
	bool soy_big_endian = soy_big_endian();
	int numero;

	while (leidos = fread(&buffer, 1, CANT_BYTES, rdptr) > 0) {
		if (!soy_big_endian) {
			char aux = buffer[0];
			buffer[0] = buffer[1];
			buffer[1] = aux;
		}

		numero = atoi(buffer);
		
		if (numero % 3 != 0) {
			fwrite(&buffer,1,leidos,wrptr);
		}
	}

	ftruncate(fileno(wrptr),ftell(wrptr));

	fclose(rdptr);
	fclose(wrptr);

	return 0;


}