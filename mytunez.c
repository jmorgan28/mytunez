#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

//song_node *table[26];


void print_list(struct song_node *n){
  if(n == NULL || n == 0){
    printf("[]");
    return;
  }
  printf("[ ");
  while(n){
    printf("%s-", n->name);
    printf("%s ", n->artist);
    n = n->next;
  }
  printf("]\n");
}

/*struct node * insert_front(struct node *n, int i){
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
*/

int main(){
  struct song_node *f;
  f = (struct song_node *) malloc(sizeof(struct song_node));
  //char e[256] = "God only knows"; 
  //char d[256] = "Beach Boys";
  //strcpy(f->name, "God only knows");
  //strcpy(f->artist, "Beach Boys");
  struct song_node *g;
  g = (struct song_node *) malloc(sizeof(struct song_node));
  print_list(f);
  // f->next = g;
  return 0;
}

