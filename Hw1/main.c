#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
  int number;
  char name[51];
  char note[100];
  struct node * next;
} node_t;

node_t * last_notnull(node_t * head) {
  node_t * current = head;
  int counter = 1;
  while (current->next != NULL) {
    current = current->next;
    counter++;
  }
  return current;
}

void list(node_t * head) {
  node_t * current = head;
  int counter = 1;
  while (current != NULL) {
    printf("%d-  %s\n%d\n%s\n", counter, current->name, current->number, current->note);
    current = current->next;
    counter++;
  }
}

node_t * delete(node_t * head, int n) {
  node_t * current = head;
  for(int i = 1; i < n + 1; i++) {
    if(1 == n) {
      head = head->next;
      current->next = NULL;
      if(current == head) {
        head = NULL;
      }
      break;
    }
    if(i == (n - 1)) {
      current->next = current->next->next;
      break;
    }
    current = current->next;
  }
  return head;
}

int main( ) {
  node_t * head = NULL;

  char w[550] = "-----------------------------------\nWelcome to myPhoneBook! Please select an option:\n1. New entry\n2. List all entries\n3. Edit\n4. Delete\n5. Search\n6. Save and exit\n7. Load\n";

  int forever = 1;
  node_t * beforeLast = NULL;
  int numberOfEntries = 0;
  while (forever) {
    int option;
    int number;
    char name[51];
    char note[100];
    
    printf("%s", w);

    scanf("%d", &option);

    if(option == 1) {
      numberOfEntries++;
      if(head == NULL) {
        head = malloc(sizeof(node_t));

        printf("Enter a name: ");
        scanf("%s", name);
        strcpy(head->name, name);

        printf("Enter a phone: ");
        scanf("%d", &number);
        head->number = number;

        printf("Enter a note: ");
        scanf("%s", note);
        strcpy(head->note, note);

        beforeLast = head;
        head->next = NULL;
        
        printf("Entry has been successfully created. Total number of entries: %d.\n", numberOfEntries);
      } else {
        beforeLast->next = malloc(sizeof(node_t));
        printf("Enter a name: ");
        scanf("%s", name);
        strcpy(beforeLast->next->name, name);

        printf("Enter a phone: ");
        scanf("%d", &number);
        beforeLast->next->number = number;

        printf("Enter a note: ");
        scanf("%s", note);
        strcpy(beforeLast->next->note, note);

        beforeLast = beforeLast->next;
        beforeLast->next = NULL;

        printf("Entry has been successfully created. Total number of entries: %d.\n", numberOfEntries);

      }
    } else if(option == 2) {
      list(head);
    } else if(option == 3) {
      continue;
    } else if(option == 4) {
      int nTBD;
      printf("Please enter the number of the entry to be deleted: \n");
      scanf("%d", &nTBD);
      printf("Deleting #%d\n", nTBD);
      head = delete(head, nTBD);
      beforeLast = last_notnull(head);
      continue;
    } else if(option == 5) {
      continue;
    } else if(option == 6) {
      break;
    } else if(option == 7) {
      continue;
    } else {
      printf("Opps. Wrong input.");
    }
  }

  return 0;
}