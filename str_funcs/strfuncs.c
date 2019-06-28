#include <stdio.h> 
#include <string.h> 


int mystrlen(char *);
char *mystrncpy(char *dest, char *source, int n);
char *mystrcat(char *dest, char *source); 
int mystrcmp(char *s1, char *s2);
char *mystrchr(char *s, char c);
char *mystrstr( char *s1, char *s2 );


int main(){

  char s1[50] = ""; 
  char s2[50] = "foo";
  char s3[50] = "spam";
  
  //Prints out all strings
  printf("s1: %s\n", s1);
  printf("s2: %s\n", s2);
  printf("s3: %s\n", s3);
  
  //Strlen
  printf("\nTesting strlen(s2)\n");
  printf("[original]: %zd\n",strlen(s2));
  printf("[mine]: %d\n",mystrlen(s2));

  //Strncopy
  printf("\nTesting strncpy(s1, s3, 2)\n");
  printf("[original]: %s\n", strncpy(s1, s3, 2));
  printf("[mine]: %s\n", mystrncpy(s1, s3, 2));
 
  //Strcat
  printf("\nTesting strcat(s1, s3)\n");
  printf("[original]: %s\n", strcat(s1, s3));
  mystrncpy(s1,s3,2);
  printf("[mine]: %s\n", mystrcat(s1, s3));

  //strchr
  printf("\nTesting strchr(s1, 's')\n");
  printf("[original]: %p\n", mystrchr(s1,'s'));
  printf("[mine]: %p\n", strchr(s1,'s'));

  //strstr
  printf("\nTesting strstr(s1, s2)\n");
  printf("[original]: %p\n", mystrstr(s1,s2));
  printf("[mine]: %p\n", strstr(s1,s2));
  
  char * a1 = "ab";
  char * a2 = "abc";
  
  //strcmp
  printf("\nTesting strcmp\n");
  printf("Comparing ab to abc:\n");
  printf("[original]: %d\n", strcmp(a1,a2));
  printf("[mine]: %d\n", mystrcmp(a1,a2));
  
  printf("\nComparing abc to ab:\n");
  printf("[original]: %d\n", strcmp(a2,a1));
  printf("[mine]: %d\n", mystrcmp(a2,a1));
  
  printf("\nComparing abc to abc:\n");
  printf("[original]: %d\n", strcmp("abc","abc"));
  printf("[mine]: %d\n", mystrcmp("abc","abc"));

  
}

int mystrlen(char *value){
  int count = 0;
  while(value[count]){
    count += 1;
  }
  return count; 
}

char *mystrncpy(char *dest, char *source, int n){
  int count = 0; 
  while(count < n){
    dest[count] = source[count];
    count++;
  }
  dest[n] = '\0';
  return dest; 
}

char *mystrcat(char *dest, char *source){
  int totalSize = mystrlen(dest) + mystrlen(source);
  char arr[totalSize];
  int counter = mystrlen(dest);
  int sourceCount = 0;

  mystrncpy(arr, dest, mystrlen(dest)); 
  while(counter < totalSize){
    arr[counter] = source[sourceCount];
    counter += 1;
    sourceCount += 1; 
  }

  mystrncpy(dest, arr, totalSize);
  return dest; 

}

int mystrcmp(char*a, char*b){
  int a_len = mystrlen(a);
  int b_len = mystrlen(b);
  int i = 0;
  int ans = 0;
  while (*(a+i) && *(b+i)){
    ans = *(a+i) - *(b+i);
    if(!ans) i++;
    else return ans;
  }
  if(a_len < b_len) return -b[a_len];
  else return a[b_len];
}


char * mystrchr( char *s, char c ){
  int i;
  for(i = 0; i<strlen(s); i++)
    if(s[i] == c) return s+i;
  return NULL;
}


char * mystrstr( char *s1, char * s2 ){
  int s1L = strlen(s1);
  int s2L = strlen(s2);
  int i = 0;
  int x;
  while( i < s1L ){
    if(s1[i] == s2[0]){
      for(x = 0; x < s2L; x++)
	if(s1[i+x] != s2[x]) break;
      return s1 + i;
    }
    i++;
  }
  return NULL;
}




