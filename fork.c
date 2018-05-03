#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <errno.h>
#include <locale.h>
#include <time.h>

#define emperror(r) { fprintf(stderr, "%s:%d errno = %d: %s\n", __FILE__, __LINE__-1, r, strerror(r)); exit(r); }

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

void child_process()
{
}

void parent_process()
{
}

int main(int argc, char *argv[])
{
	pid_t pid;
	int i;
	for (i = 0; i < NUM_CHILDREN; i++) {
		errno = 0;
		pid = fork();
		if (pid == -1) emperror(errno);
		if (pid == 0) {
			break; // don't continue fork()ing if we're a child
		}
	}

	if (pid == 0) {
		child_process();
	}
	else {
		parent_process();
	}

	return EXIT_SUCCESS;
}
