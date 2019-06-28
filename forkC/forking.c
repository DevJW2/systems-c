#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h> 

int main(){

  printf("This Process: %d\n\n", getpid());

  pid_t f = fork();

  //Forks again if it's parent
  if (f > 0) {
    f = fork();
  }
  printf("fork %d\t", f);
  
  if(f == 0){
    printf("Child PID: %d\n", getpid());
    
    srand(getpid());
    int sleep_time = (rand() % 16) + 5;
    
    printf("Child %d sleeping...\n", getpid());
    printf("SLEEP TIME: %d\n\n", sleep_time);
    sleep(sleep_time);
    
    printf("Child %d has terminated\n", getpid());
    return sleep_time; //For WEXITSTATUS, makes sure WIFEXITED by returning
  }
  else if(f > 0){

    int status;
    printf("Parent PID: %d\n\n", getpid());

    printf("Child terminated PID: %d\t", wait(&status));
    printf("Child slept: %d seconds\n", WEXITSTATUS(status));

    printf("\nParent %d has been terminated\n", getpid());
    exit(0);
  }
  else{
    printf("Fork failed\n");
  }

  return 0; 
}
