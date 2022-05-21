#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	
	FILE* file = fopen("medidas.txt","r+");

	char buffer[3];
	int leidos = 0;
	int escritos = 0;

	while (fread(&buffer, sizeof(char),3,file)) {
		leidos += 3;
		
		int numero = atoi(buffer);

		memset(&buffer,0,3);
		snprintf(buffer,3,"%02x",numero);

		fseek(file, escritos, SEEK_SET);
		fwrite(buffer,sizeof(char),2,file);
		fseek(file, leidos, SEEK_SET);
		escritos += 2;
	}

	ftruncate(fileno(file), escritos);

	fclose(file);

	return 0;
}