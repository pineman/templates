#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define chk_perror() { if (errno) { fprintf(stderr, "%s:%d %s\n", __FILE__, __LINE__-1, strerror(errno)); exit(errno); } }

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");

	return EXIT_SUCCESS;
}
