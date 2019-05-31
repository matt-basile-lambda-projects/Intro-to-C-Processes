#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *ent;
  struct stat buf;

  // Parse command line

  // Open directory
  dir = opendir(".");
  
  if(dir == NULL){
    printf("Error! Unable to open directory");
    exit(1);
  }
  while( (ent=readdir(dir)) != NULL ){
    char *name = ent->d_name;
    printf(">> %s\n", name);
    // printf(">> %1llu\n", ent->d_ino);
    stat(name, &buf);
    printf("file size is %lld\n", buf.st_size);
  }
  


  // Repeatly read and print entries

  // Close directory
  closedir(dir);
  return 0;
}