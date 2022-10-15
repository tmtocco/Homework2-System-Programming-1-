#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char caesar(char s, int n) {
  int asciiValue = (int)s;

  if(asciiValue >= 97 && asciiValue <= 122) {
    asciiValue += n;
    if (asciiValue > 122) asciiValue -= 26;
    return (char)asciiValue;
    
  } else if(asciiValue >= 65 && asciiValue <= 90) {
    asciiValue += n;
    if (asciiValue > 90) asciiValue -= 26;
    return (char)asciiValue;
    
  } else {
    return s;
  }
  
  
}