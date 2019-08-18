#include "../../lib/common.h"


void send_data(FILE *fp, int sockfd);

int main(int argc, char **argv)
{
	int                 sockfd;
	struct sockaddr_in  servaddr;

	if (argc != 2)
		error(1, 0, "usage: tcpclient <IPaddress>");

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	connect(sockfd, (SA *) &servaddr, sizeof(servaddr));
	send_data(stdin, sockfd);
	exit(0);
}

# define MESSAGE_SIZE 10240000
void send_data(FILE *fp, int sockfd)
{
	char * query;
	int i;
	query = malloc(MESSAGE_SIZE+1);
	for(i=0; i< MESSAGE_SIZE; i++){
		query[i] = 'a';
	}
	query[MESSAGE_SIZE] = '\0';

	const char *cp;
	cp = query;
	ssize_t remaining = strlen(query);
	while (remaining) {
		ssize_t n_written = send(sockfd, cp, remaining, 0);
		fprintf(stdout, "send into buffer %ld \n", n_written);
		if (n_written <= 0) {
			perror("send");
			return;
		}
		remaining -= n_written;
		cp += n_written;
	}

	return;
}

