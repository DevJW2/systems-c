#include "header.h"

int main(){
  int file, sid, shmid;
  sid = semget(SEMKEY, 1, 0);
  if(sid == -1){
    printf("Create a story!\n");
    exit(0);
  }
  //-----Access resources-----
  printf("Waiting for Access...\n");
  
  //For SEMOPS
  struct sembuf sb;
  sb.sem_num = 0; //index of semaphore
  sb.sem_op = -1; //DOWN, Decreases SEMVAL to 0
  sb.sem_flg = SEM_UNDO; //safety measures

  //Waits for semval to be upped to 1 for access
  semop(sid, &sb, 1);
  printf("Semaphone Access Granted...\n\n");

  //Gets shared memory segment
  shmid = shmget(SHMKEY, 1, 0);
  //attaches segment to variable
  int * size = shmat(shmid, 0, 0);

  //open file
  file = open("story", O_RDWR | O_APPEND);

  //-----After access, display last line-----

  //gets lines
  char * line = (char *)calloc(1, *size + 1);

  //last line
  //offset measured relative to the end of the file
  lseek(file, -1 * *size, SEEK_END); //changes r/w of file descriptor
  read(file, line, *size);
  printf("Previous line added:\n");
  printf("%s\n", line);
  free(line);
  
  //-----Prompt for next line-----
  char usr_input[1000];
  printf("Write your next line...\n");
  fgets(usr_input, sizeof(usr_input), stdin);
  
  //-----Write to file, update shared memory, release semaphore-----
  //write
  lseek(file, 0, SEEK_END);
  printf("%s", file);
  write(file, usr_input, strlen(usr_input));

  //update shared memory
  *size = strlen(usr_input); //update shared memory segment size
  shmdt(size); //detach segment

  //release semaphore
  //UP
  sb.sem_op = 1;
  semop(sid, &sb, 1);
  

}
