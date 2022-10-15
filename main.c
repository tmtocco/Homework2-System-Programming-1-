#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  FILE *filePointer;
  char* pathExisting = argv[1];
  char* pathCreate = argv[2];
  int offset = atoi(argv[3]);

  printf("Existing path: %s\n", pathExisting);
  printf("New path: %s\n", pathCreate);
  printf("Offset: %d\n",offset);
  
  filePointer = fopen(pathExisting, "w");
  
  if(filePointer == NULL) {
    printf("Error found within existing path! Exiting program.");
    exit(0);
  }
  /*
  if() {
    
    printf("Error found within creating path! Exiting program.");
  }
  */
  if(offset > 25 || offset < -25) {
    printf("Error found within offset value! Exiting program.");
    exit(0);
  }
  
  printf("pathname of existing file: ");
  scanf("%s", pathExisting);

  
  
  return 0;
}
