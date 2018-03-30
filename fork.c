#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define chk_perror() { if (errno) { fprintf(stderr, "%s:%d errno = %d: %s\n", __FILE__, __LINE__-1, errno, strerror(errno)); exit(errno); } }

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

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
		if (pid == -1) chk_perror();
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
