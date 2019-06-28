#include "pipe_networking.h"


int main() {

  int to_client;
  int from_client;
  char input[BUFFER_SIZE];


  while(1){
    from_client = server_handshake( &to_client );
    while(read(from_client, input, sizeof(input))){
      printf("Text Received: %s\n", input);
      char *s = input;
      while((*s = toupper(*s))){
	s++;
      }
      write(to_client, input, sizeof(input));
    }
  }

  return 0;
  

  
}
