#include "header.h"

void make_story(){
  int sid = semget(SEMKEY, 1, IPC_CREAT | IPC_EXCL | 0644);
  int shmid, val, file;
  
  if(sid == -1){
    printf("Semaphore already exists\n");
  }
  else{
    //Creating semaphore
    union semun su;
    su.val = 1;
    val = semctl(sid, 0, SETVAL, su);
    printf("semaphore created: %d\n", sid);
    printf("value set: %d\n", su.val);
    
    //Create shared memory
    shmid = shmget(SHMKEY, 256, IPC_CREAT | IPC_EXCL | 0644);
    printf("Shared memory created...\n");

    //Create file
    file = open("story", O_CREAT | O_RDWR | O_TRUNC, 0644);
    printf("File created...\n");
    close(file);
 
  }
  
}

//semget(key_t key, int nsems, int semflg);
char * get_current_story(){
  int file;
  struct stat story_c;
  stat("story", &story_c);
  file = open("story", O_RDONLY);
  
  if(file == -1){
    printf("Create a story!\n");
    exit(1);
  }
  else{
    int storage = story_c.st_size;
    char * size = malloc(storage);
    read(file, size, storage);
    return size;
  }
}

void get_story(){
  char * story = get_current_story();
  printf("\nCurrent Story: \n\n%s\n", story);
  free(story);
}

void remove_ss(){
  int sid = semget(SEMKEY, 0 ,0644);
  printf("semaphore removed, zero? : %d\n", semctl(sid, 0, IPC_RMID));

  int shmid = shmget(SHMKEY, 1, 0);
  printf("Shared memory removed, zero? : %d\n", shmctl(shmid, IPC_RMID, 0));

  get_story();

  //remove file
  remove("story");
   
}




int main(int argc, char ** argv){
  
  if(argv[1] == NULL){
    printf("Enter arguments: -c, -v, -r... \n");
    return 0;
  }
  
  
  if(strcmp(argv[1], "-c") == 0){
    make_story();
  }
  else if(strcmp(argv[1], "-v") == 0){
    get_story();
  }
  else if(strcmp(argv[1], "-r") == 0){
    remove_ss();
  }
  else{
    printf("Enter a valid argument");
  }


  return 0;
  
}

