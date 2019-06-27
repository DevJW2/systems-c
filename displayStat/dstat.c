#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

char* readable(double size) {
  char* readable =(char *)malloc(sizeof(size));
  int i = 0;
  const char* units[] = {"B", "KB", "MB", "GB"};
  while(size > 1024) {
    size /= 1024;
    i++;
  }
  sprintf(readable, "%f%s", size, units[i]);
  return readable;
}

int main() {
  struct stat s_buff;
  stat("dstat.c", &s_buff);

  printf("STAT INFO...\n");
  printf("File size: %s\n", readable(s_buff.st_size));
  printf("Mode: %d\n", s_buff.st_mode);
  printf("Readable File Permissions:");

  if(s_buff.st_mode & S_IRUSR){
    printf("r");
  }
  else{
    printf("-");
  }
  if(s_buff.st_mode & S_IWUSR){
    printf("w");
  }
  else{
    printf("-");
  }

  if(s_buff.st_mode & S_IXUSR){
    printf("x");
  }
  else{
    printf("-");
  }

  if(s_buff.st_mode & S_IRGRP){
    printf("r");
  }
  else{
    printf("-");
  }
  if(s_buff.st_mode & S_IWGRP){
    printf("w");
  }
  else{
    printf("-");
  }
  if(s_buff.st_mode & S_IXGRP){
    printf("x");
  }
  else{
    printf("-");
  }

  if(s_buff.st_mode & S_IROTH){
    printf("r");
  }
  else{
    printf("-");
  }
  if(s_buff.st_mode & S_IWOTH){
    printf("w");
  }
  else{
    printf("-");
  }
  if(s_buff.st_mode & S_IXOTH){
    printf("x");
  }
  else{
    printf("-");
  }
  printf("\n");
  printf("Access time: %s\n", ctime(&s_buff.st_atime));


}
