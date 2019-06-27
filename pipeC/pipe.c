#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
  int READ = 0;
  int WRITE = 1; 
	
  int fds[2];
  int fds2[2];
  int f;	

  pipe(fds);
  pipe(fds2);
  f = fork();

  if (f == 0){
    close(fds[WRITE]);
    close(fds2[READ]);
    
    int s;
    read(fds[READ], &s, sizeof(s));
    printf("child doing maths on: [%d]\n", s);
    s = s * 10 - 25;  

    write(fds2[WRITE], &s, sizeof(s));

  }
  else{
    int status;
    close(fds[READ]);
    close(fds2[WRITE]);
    
    int s = 15;
    printf("parent sending: [%d]\n", s);
    write(fds[WRITE], &s, sizeof(s));

    read(fds2[READ], &s, sizeof(s));
    printf("parent received: [%d]\n", s);
  }
  
  return 0; 
  
}
