#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

using namespace std;


int timeout_connect(const char *ip, int port, int time) {
    int ret = 0;
    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);
    address.sin_port = htons(port);

    int sock_fd = socket(PF_INET, SOCK_STREAM, 0);
    assert(sock_fd >= 0);

    struct timeval timeout;
    timeout.tv_sec = time;
    timeout.tv_usec = 0;
    socklen_t len = sizeof(timeout);
    ret = setsockopt(sock_fd, SOL_SOCKET, SO_SNDTIMEO, &timeout, len);
    assert(ret != -1);


    ret = connect(sock_fd, (struct sockaddr *) &address, sizeof(address));
    if (ret == -1) {
        if (errno == EINPROGRESS) {
            printf("Connecting timeout,process timeout logic\n");
            return -1;
        }
        printf("Error occur when connecting to server\n");
        return -1;
    }


    return sock_fd;
}

int main(int argc, char *argv[]) {
    if (argc <= 2) {
        printf("usage: %s ip_address port_number\n", basename(argv[0]));
        return 1;
    }
    const char *ip = argv[1];
    int port = atoi(argv[2]);

    int sockfd = timeout_connect(ip, port, 10);
    if (sockfd < 0) {
        return 1;
    }
    printf("progress finished!\n");
    return 0;
}
