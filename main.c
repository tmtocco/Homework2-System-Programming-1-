#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "caesar.c"

int main(int argc, char* argv[]) {
  FILE *filePointer;
  char* pathExisting = argv[1];
  char* pathCreate = argv[2];
  int offset = atoi(argv[3]);
  char* dataToBeRead = malloc(sizeof(char[2000]));
  char* encryptedData = malloc(sizeof(char[2000]));

  printf("Existing path: %s\n", pathExisting);
  printf("New path: %s\n", pathCreate);
  printf("Offset: %d\n\n",offset);
  
  filePointer = fopen(pathExisting, "r");
  
  if(filePointer == NULL) {
    printf("Error found within existing path! Exiting program.\n");
    exit(0);
  } else {
    printf("Contents within %s: \n", pathExisting);
    
    while (fgets(dataToBeRead, 2000, filePointer) != NULL) {
      printf("%s\n\n", dataToBeRead);
    }

    fclose(filePointer);
  }
  
  if(filePointer == NULL) {
    printf("Error found within creating path! Exiting program.");
    exit(1);
    
  } else if(offset > 25 || offset < -25) {
    printf("Error found within offset value! Exiting program.\n");
    exit(2);
    
  } else {
    int length = strlen(dataToBeRead);
    for (unsigned long i=0; i < length; i++) {
      encryptedData[i] = caesar(dataToBeRead[i], offset);
      //printf("Oringinal letter: %c, Letter after encryption: %c, i: %ld\n", dataToBeRead[i], encryptedData[i], i); 
    }

    printf("\nContents of %s after encryption: \n%s\n\n", pathExisting, encryptedData);
  }

  filePointer = fopen(pathCreate, "w");
  
  if (strlen(encryptedData) > 0) {
    fputs(encryptedData, filePointer) ;
    fputs("\n", filePointer) ;
  }

  fclose(filePointer);

  filePointer = fopen(pathCreate, "r");
  
  if(filePointer == NULL) {
    printf("Error found within existing path! Exiting program.\n");
    exit(4);
  } else {
    printf("%s's new contents: \n", pathCreate);
    
    while (fgets(dataToBeRead, 2000, filePointer) != NULL) {
      printf("%s\n\n", dataToBeRead);
    }

    fclose(filePointer);
  }
  
  return 0;
}
