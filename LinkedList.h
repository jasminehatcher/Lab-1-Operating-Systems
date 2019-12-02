#include <stdbool.h>
struct node
{
  int val;
  struct node*next;
};

typedef struct node node_t;

struct list {
	node_t *head;
};

typedef struct list list_t;

// print the stuff in a list
void printlist(list_t *l);

/* Returns the length of the list. */
int list_length(list_t *l);

/* Methods for adding to the list. */
void list_add_to_back(list_t *l, int value);
void list_add_to_front(list_t *l, int value);
void list_add_at_index(list_t *l, int value, int index);

int list_remove_from_back(list_t *l);
int list_remove_from_front(list_t *l);
int list_remove_at_index(list_t *l, int index);

bool list_is_in(list_t *l, int value);
int list_get_elem_at(list_t *l, int index); //gets value at certain index
int list_get_index_of(list_t *l, int value) ; //gets index of specific value

/* Functions for allocating and freeing lists. By using only these functions,
 * the user should be able to allocate and free all the memory required for
 * this linked list library. */
list_t *list_alloc();
void list_free(list_t *l);
