#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int s;

  if(argc != 3){
    fprintf(2, "Usage: find <path> <filename>\n");
    exit(1);
  }

  // Validate path & filename
  // Recursively search through the <path> for the file with provided <filename>

  exit(0);
}
