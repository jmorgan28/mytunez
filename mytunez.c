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

char * lower(char *p){
  while(*p){
    if( (*p >= 65) && (*p <= 90)){
      *p = *p + 32;
  
	  }
  
    p ++;
    //printf("%s\n", *p);
  }
  
  return p;	
}

struct song_node * insert_front(struct song_node *n, char s[256], char a[256] ){
  struct song_node *temp;
  temp = (struct song_node *) malloc(sizeof(struct song_node));
  lower(s);
  strcpy(temp->name,s);
  strcpy(temp->artist,a);
  temp->next = n;
  return temp;
}

struct song_node * insert_order(struct song_node *n, char s[256], char a[256]){
  struct song_node *temp;
  struct song_node *ret = n;
  temp = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(temp->name,s);
  strcpy(temp->artist,a);
  lower(temp->name);
  lower(n->name);
  if(strcmp(n->name, temp->name) >= 0){
    // printf("you \n");
    temp->next = n;
    return temp;
  }
  while(n->next != NULL){
    if( (strcmp(n->name, temp->name) <= 0) && strcmp((n->next)->name, temp->name)>= 0 && n->next != NULL){
      struct song_node *second = n->next;
      n->next = temp;
      temp->next = second;
      return ret;
    }
    n = n->next;
  }

  n->next = temp;
  
  return ret;
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
  char e[256] = "God only knows"; 
  //char d[256] = "Beach Boys";
  strcpy(f->name, "God only knows");
  strcpy(f->artist, "Beach Boys");
  //f = insert_front(f, e, "beach boys");
  //struct song_node *g;
  // g = (struct song_node *) malloc(sizeof(struct song_node));
  //print_list(insert_front(f, "that" ,"so"));
  f = (insert_order(f,"A day in the life", "Beatles"));
  f = ((insert_order(f,"baaa", "Beatles")));
  print_list(f);
  print_list(((insert_order(f,"zebra", "Beatles"))));
  f = ((insert_order(f,"zz", "Beatles")));
  f = ((insert_order(f,"aaa", "Beatles")));
  f = ((insert_order(f,"bbaa", "Beatles")));
  print_list(f);
  // f->next = g;
  //print_list(f);
  //lower(e);
  //printf("%s \n", e);
  return 0;
}

