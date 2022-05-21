#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define SIZE 20

int main(int argc, char* argv[]) {
	struct addrinfo hints;
	struct addrinfo *results;

	memset(&hints,0,sizeof(struct addrinfo));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	getaddrinfo(argv[1],argv[2],&hints,&results);

	int skt_acep = socket(results->ai_family,results->ai_socktype,results->ai_protocol);
	bind(skt_acep,results->ai_addr,results->ai_addrlen);
	listen(skt_acep,5);

	freeaddrinfo();

	int peer_skt = accept(skt_acep, NULL, NULL);

	char buffer [SIZE];
	int received = 0;
	bool end = false;
	bool pack_end = false
	int result;
	while (!end) {
		memset(&buffer,0,SIZE);
		
		while (received < SIZE && pack_end == false) {
			received += recv(peer_skt, &buffer[received], SIZE - received, 0);
			if (strchr(&buffer,'=') != NULL) pack_end = true;
		}

		if (pack_end && received == 1) end = true;
		else {
			int read_pos = 0;
			char aux_buffer[SIZE];
			memset(&aux_buffer,0,SIZE);
			int written_in_aux_buffer = 0;

			for (int i = 0; i < received; i ++) {
				if (buffer[i] == '=') {
					strncpy(&aux_buffer[written_in_aux_buffer],&buffer[read_pos], i - read_pos);
					result += atoi(aux_buffer);
					memset(&aux_buffer,0,SIZE);
					written_in_aux_buffer = 0;
					printf("%d",result);
					result = 0;
				}
				else if (buffer[i] == '+') {
					strncpy(&aux_buffer[written_in_aux_buffer],&buffer[read_pos], i - read_pos);
					result += atoi(aux_buffer);
					memset(&aux_buffer,0,SIZE);
					written_in_aux_buffer = 0;
					read_pos = i + 1;
				}
			}
		}		

	}

	shutdown(skt_acep, SHUT_RDWR);
	shutdown(peer_skt, SHUT_RDWR);
	close(skt_acep);
	close(peer_skt);
	
	return 0;
}