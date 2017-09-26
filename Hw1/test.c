#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
  char str[15] = "anan";

  for(int i = 0; i < strlen(str); i++) {
    printf("%c\n", str[i]);
  }

  // scanf("%s", str);
  // printf("%s\n", str);

  // char lowerstr[15];
  // for(int i = 0; str[i]; i++){
  //   if(islower(str[i]) == 0){
  //     lowerstr[i] = tolower(str[i]);
  //   } else {
  //     lowerstr[i] = str[i];
  //   }
  // }

  // printf("%s\n", lowerstr);
  return 0;
}