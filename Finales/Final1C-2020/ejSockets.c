#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdbool.h>
#include <string.h>

#include <unistd.h>
#include <netdb.h>


bool control_de_estados(char byte_received, int* estado_actual) {
	if (*estado_actual == 0) {
		if (byte_received == 'F') {
			*estado_actual ++;
		} else {
			printf("%c", byte_received);
		}

		return false;

	} else if (*estado_actual == 1) {
		if (byte_received == 'I') {
			*estado_actual ++;
		} else {
			printf("F");
			printf("%c", byte_received);
			*estado_actual = 0; 
		}

		return false;
	} else {
		if (byte_received == 'N') {
			*estado_actual ++;
			return true;
		} else {
			printf("FI");
			printf("%c", byte_received);
			*estado_actual = 0; 
			return false;
		}
	}
}

int main (int argc, char* argv) {

	struct addrinfo hints;
	struct addrinfo *results, *ptr;

	memset(&hints, 0, sizeof(struct addrinfo));

	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = 0;

	int skt_acep = socket(hints.ai_family, hints.ai_socktype, 0);

	//asumo que la ip viene en el primer argumento y el puerto en el segundo
	getaddrinfo(argv[1], argv[2], &hints, &results);

	//Supongo el caso ideal en el que se bindea a la primera correctamente
	bind(skt_acep, results->ai_addr, results->ai_addrlen);

	freeaddrinfo(results);

	listen(skt_acep,10);

	int peer_skt = accept(skt_acep, NULL, NULL);

	shutdown(skt_acep, SHUT_RDWR);
	close(skt_acep);

	
	char byte_received;
	bool end = false;
	int estado_actual = 0;
	
	while (!end ) {
		if (recv(peer_skt, &byte_received, 1, 0) <= 0) break;

		end = control_de_estados(byte_received, &estado_actual);		
	}

	shutdown(peer_skt, SHUT_RDWR);
	close(peer_skt);

}