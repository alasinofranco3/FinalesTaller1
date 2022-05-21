#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char* argv[]) {
	struct addrinfo hints;
	struct addrinfo *results;

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = 0;

	int result = getaddrinfo("127.0.0.1", "2000", &hints, &results);

	//Supongo caso en el que nos conectamos a la primera
	int skt = socket(results->ai_family,results->ai_socktype, results->ai_protocol);
	result = connect(skt, results->ai_addr, results->ai_addrlen);

	freeaddrinfo(results);

	char buffer [4] = "hola";
	int sent = 0;

	while (sent < 4) {
		sent += send(skt,&buffer[sent],4 - sent,0);
	}

	shutdown(skt,SHUT_RDWR);
	close(skt);

	return 0;
}
