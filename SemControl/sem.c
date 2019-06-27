#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SEMKEY (2781)

void open_sem(char * value){
  int sid = semget(SEMKEY, 1, IPC_CREAT | IPC_EXCL | 0664);
  if(sid == -1){
    printf("semaphore already exists\n");
  }
  else{
    int data;
    sscanf(value, "%d", &data); 
    semctl(sid, 0, SETVAL, data); 
    printf("semaphore created: %d\n", sid);
    printf("value set: %s\n", value);
  }
  
}

//semget(key_t key, int nsems, int semflg);
void get_current(){
  int sid = semget(SEMKEY, 0, 0664);
  printf("semaphore value: %d\n", semctl(sid, 0, GETVAL));
}

void remove_sem(){
  int sid = semget(SEMKEY, 0 ,0664);
  printf("semaphore removed, zero? : %d\n", semctl(sid, 0, IPC_RMID));
}




int main(int argc, char ** argv){
  
  if(argv[1] == NULL){
    printf("Enter arguments: -c, -v, -r... \n");
    return 0;
  }
  
  
  if(strcmp(argv[1], "-c") == 0){
    if(argv[2] != NULL){
      open_sem(argv[2]);
    }
    else{
      printf("Enter a value...\n");
    }
  }
  else if(strcmp(argv[1], "-v") == 0){
    get_current();
  }
  else if(strcmp(argv[1], "-r") == 0){
    remove_sem();
  }


  return 0;
  
}
