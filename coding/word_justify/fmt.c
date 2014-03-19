#include <stdio.h>
#include "word.h"
#include "line.h"
#include <string.h>


#define MAX_WORD_LENGTH 20

int main(void) {
    char word[MAX_WORD_LENGTH+1];
    int word_length = 0;
    clearline();
     while (1) {
        read_word(word, MAX_WORD_LENGTH);
        word_length = strlen(word);
        if(word_length == 0) {
            flushline();
            break;
        } 
        if (word_length > space_remain()) {
            writeline();
        } 
        addword(word);
      
    }
    return 0;
}
 
