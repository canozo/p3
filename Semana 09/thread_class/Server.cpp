#include "Server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

Server::Server(int puerto)
{
	this->puerto = puerto;
}

void* Server::run(void* arg)
{
	int n;
	int sockfd, newsockfd;
	socklen_t clilen;
	char buffer[256];
	struct sockaddr_in serv_addr, cli_addr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	{
		perror("ERROR al abrir socket");
		exit(1);
	}

	//bzero((char *) &serv_addr, sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(puerto);

	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
	{
		perror("ERROR en binding");
		exit(1);
	}

	while(true)
	{
		listen(sockfd,5);
		clilen = sizeof(cli_addr);
		newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

		if (newsockfd < 0)
		{
			perror("ERROR al aceptar");
			exit(1);
		}

		//bzero(buffer,256);

		n = read(newsockfd,buffer,255);

		if (n < 0)
		{
			perror("ERROR leyendo del socket");
			exit(1);
		}

		// printf("AquÃ­ estÃ¡ el mensaje: %s\n",buffer);
		msjBuff << "Aqui esta el mensaje: " << buffer << "\n";
		n = write(newsockfd,"Recibi tu mensaje", 18);

		if (n < 0)
		{
			perror("ERROR al escribir al socket");
			exit(1);
		}
	}

	close(newsockfd);
	close(sockfd);
	pthread_exit(NULL);
}