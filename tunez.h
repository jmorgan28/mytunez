
typedef struct song_node;

char * lower(char *p);

void print_list(struct song_node *n);

int length_list(struct song_node *n);

struct song_node * insert_front(struct song_node *n, char s[256], char a[256] );

struct song_node * insert_order(struct song_node *n, char s[256], char a[256]);

struct song_node * find_song(struct song_node *n, char *s[256]);

struct song_node * find_first_artist(struct song_node *n, char *s[256]);

struct node * free_list( struct song_node *n );

struct song_node * rem(struct song_node *n, int i);

void add_song(char *s, char *n);

struct song_node * search_song(char *s);

struct song_node * search_artist(char *n);

void print_let(char n);

void print_lib();

void shuffle();

void print_artist(char *n);

void rem_song(char *n);

void delete();
