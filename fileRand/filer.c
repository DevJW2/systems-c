//Jeffrey Weng
//Period 10

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdio.h> 


int get_random_num(){
  int num;
  int r = open("/dev/random", O_RDONLY);
  read(r, &num, sizeof(num));
  close(r);
  return num;
}

int main(){
  
  int arr[11];
  int arr2[11];

  //Populate the array with 10 random numbers
  int i;
  printf("\nRandom numbers in array: \n");
  for(i = 0; i < 11; i++){
    arr[i] = get_random_num();
    printf("Number %d: %d\n", i, arr[i]);
  }
  
  //Writes the array to the file foo
  printf("\nWriting numbers to file...\n");
  int file = open("foo", O_CREAT | O_WRONLY, 0644);
  write(file, arr, sizeof(arr));
  close(file);

  //Reads the file into another array
  printf("\nReading numbers from file...\n");
  file = open("foo", O_RDONLY);
  read(file, arr2, sizeof(arr2));
  close(file);

  //prints out the content of the other array
  printf("\nVerification...\n\n");
  printf("Numbers in array: \n");
  for(i = 0; i < 11; i++){  
    printf("Number %d: %d\n",i, arr2[i]);
  }
  printf("\n");
  
  return 0;
  
}

