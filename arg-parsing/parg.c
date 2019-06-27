#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h> 
#include <signal.h> 
#include <fcntl.h>
#include <errno.h>
#include <string.h>

char ** parse_args(char * line);

int main(){
  char line[100] = "ls -a -l";
  char ** args = parse_args(line);
  execvp(args[0], args);

  return 0;
  
}

char ** parse_args(char * line){
  char ** s1 = (char **)calloc(6, sizeof(line));

  int i = 0;
  while(line){
    s1[i] = strsep(&line, " ");
    i++;
  }

  //Test Code
  /*
  int x;
  for(x = 0; x < 6; x++){
    printf("arguments: %s\n", s1[x]);
  }
  */
  
  return s1;
}
