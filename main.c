#include <stdio.h>
#include <stdlib.h>
#include "tunez.h"

int main(){ // make main file
  srand(time(NULL));
  printf("START OF TESTING --- TESTING SECOND SET FUNCTIONS WHICH USE FIRST SET PROVING THEY TOO WORK\n");
  printf("Adding songs beach boys-wouldnt it be nice, beach boys-god only knows, beach boys-i just wasnt made for these times, beatles-a day in the life\n");
  printf("Adding songs cat stevens-father and son cat stevens-where do the children play randy newman-short people\n");
  add_song("wouldnt it be nice", "beach boys");
  add_song("god only knows", "beach boys");
  add_song("i just wasnt made for these times", "beach boys");
  add_song("a day in the life", "beatles");
  add_song("father and son", "cat stevens");
  add_song("where do the children play", "cat stevens");
  add_song("short people", "randy newman");
  printf("TESTING PRINT LIBRARY AND ADD SONG\n");
  print_lib();
  printf("TESTING SEARCH SONG -- returns node with song, will use print to show\n");
  printf("search god only knows\n");
  print_list(search_song("god only knows"));
  printf("search not a song\n");
  print_list(search_song("not a song"));
  printf("TESTING SEARCH ARTIST -- returns first node with artist, will use print to show\n");
  printf("search artist beatles\n");
  print_list(search_artist("beatles"));
  printf("search artist cat stevens\n");
  print_list(search_artist("cat stevens"));
  printf("search artist the kinks\n");
  print_list(search_artist("the kinks"));
  //printf("\n");
  printf("TESTING PRINT LETTER ENTRIES\n");
  printf("print under b\n");
  print_let('b');
  printf("print under w\n");
  print_let('w');
  printf("TESTING PRINT ARTIST\n");
  printf("print the beach boys\n");
  print_artist("beach boys");
  printf("TESTING SHUFFLE ARTIST\n");
  printf("shuffle:\n");
  shuffle();
  printf("shuffle again:\n");
  shuffle();
  printf("TESTING DELETE SONG\n");
  printf("deleting god only knows:\n");
  rem_song("god only knows");
  print_lib();
  printf("deleting father and son:\n");
  rem_song("father and son");
  print_lib();
  printf("DELETE ALL NODES -- nodes deleted then printed\n");
  delete();
  printf("print afrer deletion, nothing prints because null and free\n");
  print_lib();
  return 0;
  
}

