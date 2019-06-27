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


static void sighandler(int signo){

  char message[256] = "Interrupted due to SIGINT\n";
  
  if (signo == SIGINT){
    printf("%s", message);

    //writes to file
    int file = open("interrupt", O_CREAT | O_WRONLY, 0644);
    write(file, message, sizeof(message));
    close(file);
    //exits the program
    exit(1);
  }

  if (signo == SIGUSR1){
    printf("Parent PID: %d\n", getppid());
  }
  
}


int main(){

  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  //takes two arguments:
  //the signal to be intercepted and the handler
  
  while(1){
    printf("PID: %d\n", getpid());
    sleep(1);
  }

  return 0;
}
