#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define PROMPT "lsls$ "
#define MAX_COMMANDLINE_SIZE 2048
#define MAX_TOKENS 100

char **parse_commandline(char *commandLine, char **args, int *args_count)
{
   char *token;
// dont forget to dereference since arg_counts came in as a pointer
   *args_count = 0;
   token = strtok(commandLine, " \t\n\r");

   while(token != NULL){
    // put the token in the args array
    args[*args_count] = token;
    (*args_count)++;
    token = strtok(NULL, " \t\n\r");
   }
 //   add NULL to the end of args array to indicate there are no more args
    args[*args_count] = NULL;
    return args;
}
/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *ent;
  struct stat buf;
  char commandLine[MAX_COMMANDLINE_SIZE];
  char *args[MAX_TOKENS];
  int args_count;

  // Parse command line
  while(1){
        // print the prompt
        printf("%s", PROMPT);
        // get input from the keyboard fromt he standard input stream
        fgets(commandLine, sizeof(commandLine), stdin);
        // be able to exit the shell
        // to do that let's check for end of file (CTRL+D)
        if(feof(stdin)){
            break;
        }
        // handling parsing the command line args
        parse_commandline(commandLine, args, &args_count);

        // for(int i = 0; i <args_count; i++){
        //     printf("%s\n", args[i]);
        // }
        //  printf("%d\n", args_count);
        //  check if user didnt give any commands:
        if(args_count == 0){
            continue;
        }
        // allow user to exit by typing exit
        if(strcmp(args[0], "exit") ==0){
            break;
        }
        // Open directory
        dir = opendir(args[0]);
        
        if(dir == NULL){
          printf("Error! Unable to open directory");
          exit(1);
        }
        while( (ent=readdir(dir)) != NULL ){
          char *filename = ent->d_name;
          stat(filename, &buf);
          printf("%lld", buf.st_size);
          printf("  %s\n", filename);
          // printf(">> %1llu\n", ent->d_ino);
          
        }
  }


  // Repeatly read and print entries

  // Close directory
  closedir(dir);
  return 0;
}