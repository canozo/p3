#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
	int n;
	int sockfd, newsockfd, portno;
	socklen_t clilen;
	char buffer[256];
	struct sockaddr_in serv_addr, cli_addr;

	if (argc < 2)
	{
		fprintf(stderr,"ERROR, no se indicÃ³ puerto\n");
		exit(1);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	{
		perror("ERROR al abrir socket");
		exit(1);
	}

	//bzero((char *) &serv_addr, sizeof(serv_addr));

	portno = atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);

	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
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

		printf("AquÃ­ estÃ¡ el mensaje: %s\n",buffer);
		n = write(newsockfd,"RecibÃ­ tu mensaje",18);

		if (n < 0)
		{
			perror("ERROR al escribir al socket");
			exit(1);
		}
	}

	close(newsockfd);
	close(sockfd);
	return 0;
}
