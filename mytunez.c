#include <stdio.h>
#include <stdlib.h>
#include<string.h>

// may need to change insert to take into acocunt aritist

typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

song_node *table[26]; 

void print_list(struct song_node *n){
  if(n == NULL || n == 0){
    printf("[]");
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

struct song_node * insert_order(struct song_node *n, char s[256], char a[256]){// change so "artist - song" 
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
  if(i == 0){
    return n->next;
  }
  struct song_node *rem = n;
  int k = 0;
  while(k < i-1){
    k ++;
    n = n->next;
  }
  n->next = (n->next)->next;
  return rem;
}

void add_song(char *s, char *n){// capuitalization 
  char rem = n[0] - 97;
  if(table[rem] == 0){
    table[rem] = (struct song_node *) malloc(sizeof(struct song_node));
  }
  insert_order(table[rem],s,n);
}
  

int main(){
  /*
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
  print_list(((insert_order(f,"ZEbRA", "Beatles"))));
  f = ((insert_order(f,"zz", "BeaTles")));
  f = ((insert_order(f,"aAA", "Beatles")));
  f = ((insert_order(f,"bbaa", "Beatles")));
  f = ((insert_order(f,"bzzz", "Bzzzes")));
  print_list(f);
  print_list(find_song(f,"AAA"));
  printf("----\n");
  print_list(find_first_artist(f,"beatles"));
  print_list(f);
  printf("%d\n" ,length_list(f));
  //print_list(f);
  //printf("----\n");
  //print_list(rem(f,5));
  // f->next = g;
  //print_list(f);
  //lower(e);
  //printf("%s \n", e);
  */
  printf("--------------------\n");
  add_song("smells Like Teen Spirit", "nirvana");
  add_song("saells Like Teen Spirit", "nirvana");
  add_song("szells Like Teen Spirit", "nirvana");
  print_list(table[13]);
  return 0;
}

