//Jeffrey Weng
//Period 10
//0. strcpy/strncpy
#include <string.h>
#include <stdio.h>


int main(){

  //strncopy: copies the first n characters of the array pointed to by s2 into
  //the array pointed to by s1.

  //Syntax: char *strncpy(char *s1, const char *s2, size_t n);
  
  char storage[20];

  strncpy(storage, "copy this long string", 10);
  //overwrites original 
  strncpy(storage, "again again",10);

  //adds a null to the end to terminate the string
  storage[10] = '\0';

  printf("%s\n", storage);

  

  //strcpy: copies the string pointed to by s2 into the object pointed to by s1.
  
  //Syntax: char *strcpy(char *s1, const char *s2);

  char smallerStorage[10];

  strcpy(smallerStorage, "string");

  printf("%s\n", smallerStorage);
  
  return 0;
  
}
