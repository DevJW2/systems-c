#include "pipe_networking.h"


/*=========================
  server_handshake
  args: int * to_client

  Performs the client side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int *to_client) {
  int fd;
  char message[BUFFER_SIZE];

  if(mkfifo("upsfifo", 0666) == 0){
    printf("Upstream Pipe Created!\n");
    fd = open("upsfifo", O_RDONLY);
  }
  else{
    printf("Upstream pipe failed to create");
  }

  
  read(fd, message, HANDSHAKE_BUFFER_SIZE);
  //printf("SERVER READ");
  //printf("%d", *to_client);

  remove("upsfifo");
  //printf("UP PIPE REMOVED");

  *to_client = open(message, O_WRONLY);
  write(*to_client, ACK, HANDSHAKE_BUFFER_SIZE );
  //printf("SERVER WROTE");

  read(fd, message, HANDSHAKE_BUFFER_SIZE);

  printf("SERVER ACK: %s\n", message);
  return fd; 
}


/*=========================
  client_handshake
  args: int * to_server

  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {

  int fd;
  char message[BUFFER_SIZE];

  if(mkfifo("dsfifo", 0666) == 0){
    printf("downstream Pipe Created!\n");
  
  }
  else{
    printf("downstream pipe failed to create");
  }

   
  *to_server = open("upsfifo",O_WRONLY);

  //printf("CLIENT WROTE");
  write(*to_server, "dsfifo", HANDSHAKE_BUFFER_SIZE);
    //printf("CLIENT WROTE");


  fd = open("dsfifo", O_RDONLY);

  read(fd, message, HANDSHAKE_BUFFER_SIZE);
  //printf("CLIENT_READ");
  //printf("%d", *to_server);

  remove("dsfifo");
  //printf("CLIENT_REMOVED");

  write(*to_server, ACK, HANDSHAKE_BUFFER_SIZE);
  //printf("CLEINT WROTE");

  printf("CLIENT ACK: %s\n", message);
  return fd;
}
