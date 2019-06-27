//Jeffrey Weng
//period 10


#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
  DIR *d;
  char cwd[1024];
  getcwd(cwd, sizeof(cwd));
  d = opendir(cwd);

  struct dirent *entry;
  struct stat s_buff;

  entry = readdir(d);

  printf("\nDirectory Statistics: \n");
  printf("----------------------------------------\n");
  int total_size = 0; 

  
  while(entry){
    if(entry->d_type == DT_DIR){
      printf("directory: %s\n", entry->d_name);
    }
    else{
      printf("Regular file: %s\n", entry->d_name);
      stat(entry->d_name, &s_buff);
      total_size += s_buff.st_size;
    }
    entry = readdir(d);
  } 
  printf("----------------------------------------\n");
  printf("Total Directory Size: %d\n\n", total_size);
  closedir(d);

}
