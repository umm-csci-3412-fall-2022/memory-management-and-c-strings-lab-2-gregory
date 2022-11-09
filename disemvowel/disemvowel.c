#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "disemvowel.h"

const char* vowels = "aeiouAEIOU";

bool isconsonant(char c){
	for (int j=0; j<10; ++j){
		if(c == vowels[j]){
			return false;
		}
	}

		return true;
}

char *disemvowel(char *str) {
	int consonantcount = 0;
	int len = strlen(str);
	char* disemvoweled = (char*) calloc(len+1, sizeof(char));

	for (int i=0; i<len; i++){
		if(isconsonant(str[i])){
			disemvoweled[consonantcount] = str[i];
			consonantcount++;
		}
	}

		disemvoweled[consonantcount] = '\0';
  return (char*) disemvoweled;
}
