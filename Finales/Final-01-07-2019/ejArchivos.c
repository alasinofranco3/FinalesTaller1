#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUF_LEN 32



int main(int argc, char* argv[]) {
	FILE* rdptr = fopen(argv[1], "r");
	FILE* wrptr = fopen(argv[1], "r+");

	int leidos = 0;
	int inicio_linea = 0;
	int fin_linea = 0;
	bool encontre_fin_linea = false;
	char buffer [BUF_LEN];

	while (leidos = fread(&buffer, sizeof(char), BUF_LEN, rdptr) > 0) {
		if (strchr(&buffer," ") != NULL) {
			fwrite(&buffer,sizeof(char),leidos,wrptr);
		}
		memset(&buffer,0,BUF_LEN);
	}

	ftruncate(fileno(wrptr),ftell(wrptr));
	fclose(wrptr);
	fclose(rdptr);

	return 0;
}