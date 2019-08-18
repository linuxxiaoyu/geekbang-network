#include <stdio.h>	
#include <stdlib.h>
#include <errno.h>	
#include <sys/un.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>

const MAXLINE = 1024;
const BUFFER_SIZE = 1024;
const MESSAGE_SIZE = 1024;
const LISTENQ = 1024;

const SERV_PORT = 12345;

typedef struct sockaddr SA;

