#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_LEN 10

int main (int argc, char* argv[]) {
	struct addrinfo hints;
	struct addrinfo *results;

	memset(&hints,0,sizeof(struct addrinfo));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = 0;

	getaddrinfo(argv[1],argv[2],&hints,&results);

	int skt = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
	connect(skt, results->ai_addr, results->ai_addrlen);

	freeaddrinfo(results);

	FILE* file = fopen(argv[3],"rb");

	char buffer[BUFFER_LEN];
	int sent = 0;
	int leidos = 0;
	while (leidos = fread(&buffer,1,BUFFER_LEN,file) > 0) {
		while (sent < leidos) {
			sent += send(skt,&buffer[sent],leidos-sent,0);
		}
		sent = 0;
	}

	shutdown(skt,SHUT_RDWR);
	close(skt);

	fclose(file);

	return 0;
}