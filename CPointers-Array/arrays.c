//Jeffrey Weng
//Period 10 
//Homework 3

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main(){
  srand(time(NULL));
  int array_a[10];
  int array_b[10];
  
  int *ip;
  
  //populating array with random values
  for(int i = 0; i < 10; i++){
    array_a[i] = rand();
  }
  //setting last value of the array to zero 
  array_a[9] = 0;
  
  //populating the second array with the first array
  for(int i = 9; i >= 0; i--){
    ip = &array_a[i]; 
    array_b[9-i] = *ip; 
    
  }
  
  printf("The original array\n");
  for(int i = 0; i < 10; i++){
    printf("value: %d\n", array_a[i]);
  }
  printf("The Second Array\n");
  for(int i = 0; i < 10; i++){
    printf("value: %d\n", array_b[i]);
  }
  
  
  
  
}
