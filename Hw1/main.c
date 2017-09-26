#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
  int number;
  char name[51];
  char note[100];
  struct node * next;
} node_t;

// char * lowerize(char word[])
// {
//   int len = strlen(word);
//   static char rst[50];
//   free(rst);
//   // for(int i = 0; strlen(rst); i++) {
//   //   rst[i] = ' ';
//   // }

//   for(int i = 0; word[i]; i++){
//     if(islower(word[i]) == 0){
//       rst[i] = tolower(word[i]);
//     } else {
//       rst[i] = word[i];
//     }
//   }
//   return rst;
// }

// int * search(node_t * head, char srch[20]) {
//   int x[10];
//   static int r[10];
//   int n = sizeof(r) / sizeof(int);

//   for(int i = 0; i < n; i++) {
//     r[i] = 0;
//   }

//   node_t * current = head;
//   int counter = 1;
//   int counter_found = 0;

//   char srchLower[100];

//   for(int i = 0; srch[i]; i++){
//     srchLower[i] = tolower(srch[i]);
//   }

//   printf("srch lower: %s\n", srchLower);
//   // for(int i = 0; i < 5 + 1; i++) {
//   //   printf("%d\n", r[i]);
//   // }

//   while (current != NULL) {
//     // int na = strlen(current->name);
//     // int no = strlen(current->note);
//     // printf("na: %d\n", na);
//     // printf("no: %d\n", no);
//     char * nameLower;
//     char * noteLower;

//     nameLower = lowerize(current->name);
//     noteLower = lowerize(current->note);
    
//     printf("name: %s\n", current->name);  
//     printf("nameLower: %s\n", nameLower);

//     printf("note: %s\n", current->note);
//     printf("noteLower: %s\n", noteLower);

//     if((strstr(nameLower, srch) != NULL) || (strstr(noteLower, srch) != NULL)) {
//       printf("found %s, %s\n", current->name, current->note);
//       printf("inserting to r, r[%d]=%d\n", counter_found, counter);
//       r[counter_found] = counter;
//       counter_found++;
//     }
//     current = current->next;
//     counter++;
//   }
//   // printf("indecies: \n");
//   // for(int i = 0; i < counter_found + 1; i++) {
//   //   printf("%d\n", r[i]);
//   // }
//   return r;
// }

void text(node_t * head) {
  FILE *f = fopen("pb.txt", "w");
  node_t * current = head;
  int counter = 1;
  while (current != NULL) {
    const char *name = current->name;
    const char *note = current->note;
    const int number = current->number;
    fprintf(f, "%d- %s %d %s\n", counter, name, number, note);
    counter++;
    current = current->next;
  }
  fclose(f);
}

int isvalueinarray(int val, int *arr, int size){
  int i;
  for (i=0; i < size; i++) {
      if (arr[i] == val)
          return 1;
  }
  return 0;
}

void listWithIndex(node_t * head, int * results) {
  node_t * current = head;
  int counter = 1;
  int listcounter = 1;
  int n = sizeof(results) / sizeof(int);
  while (current != NULL) {
    if(isvalueinarray(counter, results, n) == 1) {
      printf("%d-  %s\n%d\n%s\n", listcounter, current->name, current->number, current->note);
      listcounter++;
    }
    counter++;
    current = current->next;
  }
}

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

void edit(node_t * head, int n) {
  node_t * current = head;
  int counter = 1;
  int number;
  char name[51];
  char note[100];
  while (current != NULL) {
    if(n == counter) {
      printf("Edit the name: ");
      scanf("%s", name);
      strcpy(current->name, name);
  
      printf("Edit the phone: ");
      scanf("%d", &number);
      current->number = number;
  
      printf("Edit the note: ");
      scanf("%s", note);
      strcpy(current->note, note);
      break;
      return;
    }
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
      int nTBE;
      printf("Please enter the number of the entry to be edited: \n");
      scanf("%d", &nTBE);
      printf("Editing #%d\n", nTBE);
      edit(head, nTBE);
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
      char srch[20];
      printf("What are you searching for: ");
      scanf("%s", srch);
      // listWithIndex(head, search(head, srch));
      continue;
    } else if(option == 6) {
      text(head);
      break;
    } else if(option == 7) {
      continue;
    } else {
      printf("Opps. Wrong input.");
    }
  }

  return 0;
}