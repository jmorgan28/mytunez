#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
#include<math.h>
#include"tunez.h"

typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

song_node *table[26]; 

void print_list(struct song_node *n){
  if(n == NULL || n == 0){
    printf("[]\n");
    return;
  }
  printf("[ ");
  while(n){
    if(n->artist != ""){
      printf("%s-", n->artist);
      printf("%s, ", n->name);
      n = n->next;
    }
  }
  printf("]\n");
}

int length_list(struct song_node *n){
  if(n == NULL || n == 0){
    return 0;
  }
  int i = 0;
  while(n){
    i ++;
    n = n->next;
  }
  return i;
}


char * lower(char *p){
  char * temp = p;
  while(*temp){
    if( (*temp >= 65) && (*temp <= 90)){
      *temp += 32;
	  }
    temp = temp +1;
  }
  return p;	
}

struct song_node * insert_front(struct song_node *n, char s[256], char a[256] ){
  struct song_node *temp;
  temp = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(temp->name,s);
  strcpy(temp->artist,a);
  lower(temp->name);
  lower(temp->artist);
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
  lower(n->artist);
  lower(temp->artist);
  //printf("this");
  char p1[256] = "";
  strcat(p1,temp->artist);
  strcat(p1,temp->name);
  char p2[256] = "";
  strcat(p2,n->artist);
  strcat(p2,n->name);
  if(strcmp(p2, p1) >= 0){
    // printf("you \n");
    temp->next = n;
    return temp;
  }
  while(n->next != NULL){
    char p3[256] = "";
    strcat(p3,(n->next)->artist);
    strcat(p3,(n->next)->name);
    if( (strcmp(p2, p1) <= 0) && strcmp(p3, p1)>= 0 && n->next != NULL){
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

struct song_node * find_song(struct song_node *n, char *s[256]){
  struct song_node *temp;
  temp = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(temp->name,s);
  lower(temp->name);
  while(n){
    if(strcmp(n->name, temp->name) == 0){
      return n;
    }
    n = n->next; 
  }
  //printf("1\n");
  return 0; 
}


struct song_node * find_first_artist(struct song_node *n, char *s[256]){
  struct song_node *temp;
  temp = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(temp->artist,s);
  lower(temp->artist);
  while(n){
    if(strcmp(n->artist, temp->artist) == 0){
      return n;
    }
    n = n->next; 
  }
  //printf("1\n");
  return 0; 
}



struct node * free_list( struct song_node *n ) { 
  struct node *temp = n;
  while ( n ) {
    n = n->next;
    free(temp);
    temp = n;    
  }
  n = NULL;
  return n;
}



struct song_node * ret_rand(struct song_node *n){ //make more random
  
  int i = rand() % length_list(n);
  int k =0;
  while(k < i){
    n = n->next;
    k ++;
  }
  return n;
}

struct song_node * rem(struct song_node *n, int i){
  struct song_node *ret;
  ret = (struct song_node *) malloc(sizeof(struct song_node));
  ret = n;
  if(i == 0){
    return ret->next;
  }
  int k = 0;
  while(k < i-1){
    k ++;
    ret = ret->next;
  }
  ret->next = (ret->next)->next;
  //print_list(n);
  //printf("--------------------------------------\n");
  return n;
}

void add_song(char *s, char *n){
  char rem;
  if( (n[0] >= 65) && (n[0] <= 90)){
    rem = (n[0] + 32) -97;
	  }
  else{
    rem = n[0] - 97;
  }
  if(table[rem] == 0){
    table[rem] = (struct song_node *) malloc(sizeof(struct song_node));
  }
  insert_order(table[rem],s,n);
}

struct song_node * search_song(char *s){
  int i = 0; 
  while(i < 26){
    if(table[i] != NULL){
      if(find_song(table[i],s) != 0){
	return find_song(table[i],s);
      }
    }
    i ++;
  }
  return 0;
}

struct song_node * search_artist(char *n){
  char rem;
  if( (n[0] >= 65) && (n[0] <= 90)){
    rem = (n[0] + 32) -97;
	  }
  else{
    rem = n[0] - 97;
  }
  if(table[rem] != 0){
    return find_first_artist(table[rem],n);
  }
  return 0;
}

void print_let(char n){
  print_list(table[n-97]);
}

void print_lib(){
  char i = 0;
  while(i < 26){
    if(table[i] != NULL){
    print_list(table[i]);
    printf("\n");
    }
    i ++;
  }
}

void shuffle(){
  int k = 0;
  while(k < 4){
    // used to be using time
    int i = rand() % 26;
    if(table[i] != NULL){
      //printf("name:%s\n", table[i]->name);
      struct song_node *temp = ret_rand(table[i]);
      printf("%s-%s\n",temp->name, temp->artist );
      k ++;
    }
    
  }
  
}


void print_artist(char *n){
  struct song_node *temp = search_artist(n);
  while(temp!= NULL && strcmp(temp->artist,n) ==0){
    printf("%s-%s\n", temp->name, temp->artist);
    temp = temp->next;
  }
}


void rem_song(char *n){
  struct song_node *ret = search_song(n);
  char w = ((ret->artist)[0]) -97;
  // printf("%d\n", w);
  struct song_node *temp = table[w];
  struct song_node *sec = table[w];
  int i = 0;
  int rems = length_list(temp);
  //printf("%d\n", rems);
  while(i < rems -1  && strcmp(temp->name, n) != 0){
    i ++;
    temp = temp->next;
  }
  //print_list(table[w]);
  //printf("i = %d\n", i);
  if(i == 0){
  table[w] = rem(ret,i);
  }
  else{
    //printf("note:\n");
    //print_list(rem(table[w], i));
    table[w] = rem(table[w], i);
  }
}
  


void delete(){
  int i = 0;
  while(i < 26){
    table[i] = free_list(table[i]);
    i ++;
  }
}

