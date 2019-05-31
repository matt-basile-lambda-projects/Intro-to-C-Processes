#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *sd;

  // Parse command line

  // Open directory
  dir = opendir(".");
  if(dir == NULL){
    printf("Error! Unable to open directory");
    exit(1);
  }
  while( (sd=readdir(dir)) != NULL ){
    printf(">> %s\n", sd->d_name);
  }
  


  // Repeatly read and print entries

  // Close directory
  closedir(dir);
  return 0;
}