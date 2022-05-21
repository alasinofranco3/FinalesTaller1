#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define CHAU_LEN 4

bool maquina_estados(int* estado_actual, char byte) {
	if (*estado_actual == 0) {
		if (byte == 'C') {
			*estado_actual++;
		} else {
			printf("%c",byte);
		}
	} else if (*estado_actual == 1) {
		if (byte == 'H') {
			*estado_actual++;
		} else {
			printf("C");
			printf("%c",byte);
			*estado_actual = 0;
		}
	} else if (*estado_actual == 2) {
		if (byte == 'A') {
			*estado_actual++;
		} else {
			printf("CH");
			printf("%c",byte);
			*estado_actual = 0;
		}
	} else {
		if (byte == 'U') {
			return true;
		} else {
			printf("CHA");
			printf("%c",byte);
			*estado_actual = 0;
		}
	} 

	return false;
}

int main (int argc. char*argv[]) {
	struct addrinfo hints;
	struct addrinfo *results;

	memset(&hints,0,sizeof(struct addrinfo));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	getaddrinfo(argv[1],argv[2],&hints,&results);

	int skt_acep = socket(results->ai_family,results->ai_socktype, results->ai_protocol):
	bind(skt_acep,results->ai_addr,results->ai_addrlen);
	listen(skt_acep,5);

	freeaddrinfo(results);

	int peer_skt = accept(skt_acep,NULL,NULL);

	char byte;
	int estado_actual = 0;
	bool terminar = false;

	while (recv(peer_skt,&byte,1,0) > 0 && !terminar) {
		terminar = maquina_estados(&estado_actual,byte);
	}

	shutdown(peer_skt,SHUT_RDWR);
	close(peer_skt);
	shutdown(skt_acep,SHUT_RDWR);
	close(skt_acep);

	return 0;
}