#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
	int pipefd[2];
	int cpid;
	char c = 'x';

	if (argc != 1) {
		fprintf(2, "Usage: pingpong\n");
		exit(1);
	}

	if ((pipe(pipefd)) == -1) {
		fprintf(2, "pipe failure\n");
		exit(1);
	}

	cpid = fork();
	if (cpid == -1) {
		fprintf(2, "fork failure\n");
		exit(1);
	}

	if (cpid == 0) {	/* Child reads from the pipe */

		// Print the <pid>: received ping

		// Write a byte

		// exit
	} else {
		// Send a byte to the child

		// Read the byte from the child

		// Print the <pid>: received pong

		// exit
	}

	exit(0);
}
