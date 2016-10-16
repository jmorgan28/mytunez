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
    printf("%s, ", n->artist);
    n = n->next;
  }
  printf("]\n");
}

struct song_node * insert_front(struct node *n, char s[256], char a[256] ){
  struct song_node *temp;
  temp = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(temp->name,s);
  strcpy(temp->artist,a);
  temp->next = n;
  return temp;
}


struct song_node * free_list(struct song_node *n){
  struct song_node *temp;
  temp = (struct song_node *) malloc(sizeof(struct song_node));
  temp = n;
  while((*temp).next != NULL){
    struct song_node *temp1;
    temp1 = (struct song_node *) malloc(sizeof(struct song_node));
    temp = (*temp).next;
    free(temp1);
    temp1 = NULL;
  }
  n= NULL;
  return n;
}


int main(){
  struct song_node *f;
  f = (struct song_node *) malloc(sizeof(struct song_node));
  //char e[256] = "God only knows"; 
  //char d[256] = "Beach Boys";
  strcpy(f->name, "God only knows");
  strcpy(f->artist, "Beach Boys");
  //struct song_node *g;
  // g = (struct song_node *) malloc(sizeof(struct song_node));
  print_list(f);
  print_list(free_list(insert_front(f,"Girl", "Beatles")));
  // f->next = g;
  //print_list(f);
  return 0;
}

