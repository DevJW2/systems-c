// Jeffrey Weng
// Period 10
// Systems - Euler Problems #1,5,6

#include <stdio.h>
#include <stdbool.h>
#include <math.h> 

//Problem 1 - Sum of all multiples of 3 or 5 below 1000

int euler_one(){
  int value = 0;
  for(int n = 0; n < 1000; n++){
    if (n % 3 == 0 || n % 5 == 0){
	value += n;
    }
  }
  return value;
}

int euler_five(){
  bool smallest = false;
  int value = 1;
  while(!smallest){
    bool temp = false;
    for (int n = 1; n <= 20; n++){
      if(value % n == 0){
	temp = true; 
      }
      else{
	temp = false;
	break;
      }
    }
    if(temp == true){
      smallest = temp;
    }
    else{
      value += 1;
    }
  }
  return value;
}

int euler_six(){
  int total = 0;
  int sum_squares = 0;
  for (int n = 1; n <= 100; n++){
    sum_squares += n * n;
    total += n;
  }
  return  pow(total, 2) - sum_squares;
}


int main(){
  printf("Problem One: %d\n", euler_one());
  printf("Problem Five: %d\n", euler_five());
  printf("Problem Six: %d\n", euler_six());
  
  return 0;

}
