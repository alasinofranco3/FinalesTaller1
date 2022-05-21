#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int agregar_caracteres_extra(FILE* rdptr) {
	int leidos = 0;
	char byte;
	int caracteres_extra = 0;

	while (fread(&byte,1,1,rdptr) > 0) {
		leidos ++;
		if (byte == ' ' || byte == '\n') {
			if (leidos <= 4) { //leo como maximo 3 caracteres + el espacio o \n
				caracteres_extra += leidos;
				leidos = 0;
			}
		}
	}

	return caracteres_extra;
}

int main (int argc, char* argv[]) {
	FILE* rdptr = fopen(argv[1], "r");
	FILE* wrptr = fopen(argv[1], "r+");

	char guion = '-';

	int cant_adicional_de_caracteres = agregar_caracteres_extra(rdptr);

	fseek(wrptr,SEEK_END);

	//HAGO ESPACIO PARA LAS PALABRAS ADICIONALES
	for (i = 0; i < cant_adicional_de_caracteres; i++){
		fwrite(&guion,1,1,wrptr);
	}

	bool terminar = false;
	int desplazamiento_hacia_atras_rd = 1;
	int desplazamiento_hacia_atras_wr = 1;
	int leidos = 0;
	char byte;

	fseek(rdptr,-1,SEEK_CUR);
	fseek(wrptr,-1,SEEK_CUR);
	
	while (!terminar) {
		//desplazamiento_hacia_atras_rd ++;
		fread(&byte,1,1,rdptr);
		fseek(rdptr,-2,SEEK_CUR);
		if (byte == '\n') {
			fwrite(&byte,1,1,wrptr);
			fseek(wrptr, -2,SEEK_CUR);
		} else if (byte == ' ') {
			if (leidos <= 3) {
				
			} else {
				fseek(wrptr, -(leidos + 1),SEEK_CUR);
				fwrite(&byte,1,1,wrptr);
				fseek(rdptr,2,SEEK_CUR);
				for (int i = 0; i < leidos; i++) {
					fread(&byte,1,1,rdptr);
					fwrite(&byte,1,1,wrptr);
				}
				fseek(rdptr,-(2 + leidos),SEEK_CUR);
				
			}
			leidos = 0;
		} else {
			leidos ++;

		}
	}

}