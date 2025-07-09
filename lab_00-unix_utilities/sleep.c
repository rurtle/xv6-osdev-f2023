#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int s;

  if(argc < 2){
    fprintf(2, "Usage: sleep <# of seconds>\n");
    exit(1);
  }

  s = atoi(argv[1]);
  if (s == 0) {
	fprintf(2, "sleep: Duration must be a number\n");
  } else {
    sleep(s);
  }

  exit(0);
}
