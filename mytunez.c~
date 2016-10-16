#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

song_node *table[26];


struct node {int i; struct node *next;};


void print_list(struct node *n){
  if(n == NULL){
    printf("[]");
    return;
  }
  struct node *temp;
  temp = (struct node *) malloc(sizeof(struct node));
  temp = n;
  printf("[ ");
  printf("%d -", song_node->name);
  printf("%d, ", song_node->artists)
  while((*temp).next != NULL){
    temp = (*temp).next;
    printf("%d -", song_node->name);
    printf("%d, ", song_node->artists)
  }
  printf("]\n");
}

struct node * insert_front(struct node *n, int i){
  struct node *temp;
  temp = (struct node *) malloc(sizeof(struct node));
  temp->i = i;
  temp->next = n;
  return temp;
}
 
struct node * free_list(struct node *n){
  struct node *temp;
  temp = (struct node *) malloc(sizeof(struct node));
  temp = n;
  while((*temp).next != NULL){
    struct node *temp1;
    temp1 = (struct node *) malloc(sizeof(struct node));
    temp = (*temp).next;
    free(temp1);
    temp1 = NULL;
  }
  n= NULL;
  return n;
}


int main(){
  return 0;
}

