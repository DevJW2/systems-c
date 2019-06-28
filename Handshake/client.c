#include "pipe_networking.h"


int main() {

  int to_server;
  int from_server;
  char input[BUFFER_SIZE];

  from_server = client_handshake( &to_server );

  while(1){
    printf("Your message: ");
    fgets(input, sizeof(input), stdin);

    *strchr(input, '\n') = 0;

    write(to_server, input, sizeof(input));
    read(from_server, input, sizeof(input));
    printf("Text Received: %s\n", input);
  }

  return 0;
}
