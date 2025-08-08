/**
 * @name	pingpong
 *
 * @brief	Write a user-level program that uses xv6 system calls to 
 * 		''ping-pong'' a byte between two processes over a pair of pipes,
 * 		one for each direction. The parent should send a byte to the
 * 		child; the child should print "<pid>: received ping", where
 * 		<pid> is its process ID, write the byte on the pipe to the
 * 		parent, and exit; the parent should read the byte from the child,
 * 		print "<pid>: received pong", and exit. Your solution should be
 * 		in the file user/pingpong.c.
 *
 * @date	8-Aug-2025
 **/
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
	int pipefd[2];
	char c;
	int cpid;

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
		close(pipefd[0]);
		// Print the <pid>: received ping
		printf("%d: received ping\n", getpid());

		// Write a byte (we don't care what we're writing; so, anything will do)
		write(pipefd[1], "x", 1);
		// Don't forget to close the write file handle
		close(pipefd[1]);

		// exit
		exit(0);
	} else {
		// Wait for the child process to complete
		wait(0);
		// Send a byte to the child
		write(pipefd[1], "x", 1);

		// Read the byte from the child
		read(pipefd[0], &c, 1);

		// Print the <pid>: received pong
		printf("%d: received pong\n", getpid());

		// close file handles
		close(pipefd[0]);
		close(pipefd[1]);
	}

	exit(0);
}
