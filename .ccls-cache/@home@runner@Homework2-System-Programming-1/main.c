#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  FILE *filePointer;
  char* pathExisting = argv[1];
  char* pathCreate = argv[2];
  int offset = atoi(argv[3]);
  char* dataToBeRead = malloc(sizeof(char[1000]));

  printf("Existing path: %s\n", pathExisting);
  printf("New path: %s\n", pathCreate);
  printf("Offset: %d\n\n",offset);
  
  filePointer = fopen(pathExisting, "r");
  
  if(filePointer == NULL) {
    printf("Error found within existing path! Exiting program.\n");
    exit(0);
  } else {
    printf("Contents within %s: \n", pathExisting);
    
    while (fgets(dataToBeRead, 1000, filePointer) != NULL) {
      printf("%s\n\n", dataToBeRead);
    }
  }
  
  filePointer = fopen(pathCreate, "w");
  
  if(filePointer == NULL) {
    printf("Error found within creating path! Exiting program.");
    exit(1);
    
  } else if(offset > 25 || offset < -25) {
    printf("Error found within offset value! Exiting program.\n");
    exit(2);
    
  } else {
    char* encryptedData = malloc(sizeof(dataToBeRead));
    
    for (int i=0; i < sizeof(dataToBeRead); i++) {
      encryptedData[i] = caesar(dataToBeRead[i], offset);  
    }
  }
  
  
  
  return 0;
}
