#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
#if 0
	int pipefd[2];
	char c = 'x';
#endif
	int cpid;

	if (argc != 1) {
		fprintf(2, "Usage: pingpong\n");
		exit(1);
	}
#if 0
	if ((pipe(pipefd)) == -1) {
		fprintf(2, "pipe failure\n");
		exit(1);
	}
#endif

	cpid = fork();
	if (cpid == -1) {
		fprintf(2, "fork failure\n");
		exit(1);
	}

	if (cpid == 0) {	/* Child reads from the pipe */
		// Print the <pid>: received ping
		printf("%d: received ping", getpid());

		// Write a byte

		// exit
		exit(0);
	} else {
		// Send a byte to the child

		// Read the byte from the child

		// Print the <pid>: received pong
		printf("%d: received pong", getpid());

		// exit
	}

	exit(0);
}
