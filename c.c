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

int main(int argc, char *argv[])
{

	return EXIT_SUCCESS;
}
