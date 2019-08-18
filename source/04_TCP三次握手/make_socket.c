#include "../../lib/common.h"

int make_socket (uint16_t port)
{
	int sock;
	struct sockaddr_in name;


	/* 创建字节流类型的 IPV4 socket. */
	sock = socket (PF_INET, SOCK_STREAM, 0);
	if (sock < 0)
	{
		perror ("socket");
		exit (EXIT_FAILURE);
	}


	/* 绑定到 port 和 ip. */
	name.sin_family = AF_INET; /* IPV4 */
	name.sin_port = htons (port);  /* 指定端口 */
	name.sin_addr.s_addr = htonl (INADDR_ANY); /* 通配地址 */
	/* 把 IPV4 地址转换成通用地址格式，同时传递长度 */
	if (bind (sock, (struct sockaddr *) &name, sizeof (name)) < 0)
	{
		perror ("bind");
		exit (EXIT_FAILURE);
	}

	return sock;
}

int main(int argc , char** argv) {
	make_socket(SERV_PORT);
	return 0;
}
