#include <stdio.h>
#include <string.h>

typedef struct node {
  int number;
  char name[51];
  char notes[1001];
  struct node * next;
} node_t;

int main( ) {
  node_t * head = NULL;
  head = malloc(sizeof(node_t));
  if (head == NULL) {
      return 1;
  }
  
  head->val = 1;
  head->next = NULL;

  return 0;
}