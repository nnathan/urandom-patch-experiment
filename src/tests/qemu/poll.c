#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/poll.h>

#define TIMEOUT 5

int main (void)
{
	struct pollfd fds[1];
	int ret;

	int fd = open("/dev/urandom", O_RDWR);

	if (fd == -1) {
		perror ("open");
		return 1;
	}

	fds[0].fd = fd;
	fds[0].events = POLLIN|POLLOUT;

	ret = poll(fds, 1, TIMEOUT * 1000);

	if (ret == -1) {
		perror ("poll");
		return 1;
	}

	if (!ret) {
		printf ("%d seconds elapsed.\n", TIMEOUT);
		return 0;
	}

	if (fds[0].revents & POLLIN)
		printf ("urandom is readable\n");

	if (fds[0].revents & POLLOUT)
		printf ("urandom is writable\n");

	return 0;

}
