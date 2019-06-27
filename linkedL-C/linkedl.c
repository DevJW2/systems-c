//Jeffrey Weng
//Period 10
//HW 06

#include <stdio.h>
#include <stdlib.h>

struct node {int i; struct node * next;};

void print_list(struct node *);
struct node * insert_front(struct node *, int);
struct node * free_list(struct node *); 

void print_list(struct node * plist){
  printf("list content: ");
  
  while(plist){
    printf("%d,",(* plist).i);
    plist = plist->next;
  }
  printf("\n");
}

struct node * insert_front(struct node * list, int value){
  struct node * new_node = (struct node *)malloc(sizeof(*list));
  (* new_node).next = list;
  (* new_node).i = value;

  return new_node;
}

struct node * free_list(struct node * flist){
  struct node * tmp; 
  while(flist){
    tmp = (*flist).next;
    free(flist);
    flist = tmp; 
  }

  return flist; 
}

int main(){
  struct node * new_list = NULL;

  printf("Adding 1 - 9 inclusive\n");
  int i = 1;
  for(; i < 10; i++){
    new_list = insert_front(new_list, i);
  }
  print_list(new_list);

  printf("Adding 100\n");
  new_list = insert_front(new_list, 100);
  print_list(new_list);
  printf("Adding 42\n");
  new_list = insert_front(new_list, 42);
  
  print_list(new_list);
  new_list = free_list(new_list);
  printf("list after freeing: %p\n", new_list);
  return 0; 

}
