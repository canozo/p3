#include "Client.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string>

using namespace std;

Client::Client(string hostname, int puerto)
{
	// TODO ver si hay que convertir a char*
	this->hostname = hostname;
	this->puerto = puerto;
}

void* Client::run(void* arg)
{
	int sockfd, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[256];

	while (true)
	{
		if (msjEnvio.empty())
			continue;

		sockfd = socket(AF_INET, SOCK_STREAM, 0);

		if (sockfd < 0)
		{
			perror("ERROR al abrir socket");
			exit(1);
		}

		server = gethostbyname(hostname);

		if (server == NULL)
		{
			fprintf(stderr,"ERROR, no existe el host\n");
			exit(1);
		}

		bzero((char *) &serv_addr, sizeof(serv_addr));
		serv_addr.sin_family = AF_INET;
		bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
		serv_addr.sin_port = htons(puerto);

		if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
		{
			perror("ERROR connectando");
			exit(1);
		}

		// printf("Por favor escriba un mensaje: ");
		// msjBuff << "Por favor escriba un mensaje: ";
		// bzero(buffer,256);
		// fgets(buffer,255,stdin);

		n = write(sockfd, msjEnvio, msjEnvio.length());

		if (n < 0)
		{
			perror("ERROR escribiendo al socket");
			exit(1);
		}

		bzero(buffer,256);
		n = read(sockfd,buffer,255);

		if (n < 0)
		{
			perror("ERROR leyendo del socket");
			exit(1);
		}

		// printf("%s\n",buffer);
		msjBuff << buffer << "\n";
	}
	close(sockfd);
	pthread_exit(NULL);
}

void Client::setMsj(string msjEnvio)
{
	this->msjEnvio = msjEnvio;
}
