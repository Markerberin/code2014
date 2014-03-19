#include "line.h"
#include "string.h" 
#include <stdio.h> 

char line[MAX_LINE_LENGTH+1];

int space_available = 60;
int num_words = 0;

void clearline(void) {
    line[0] = '\0';
    space_available = 60;
    num_words = 0;
}


int space_remain() {
    return space_available;
}

void addword(const char *word ) {
    int cur = 60 - space_available;
    int word_len = strlen(word);
    
    while(1) {
        if( (line[cur++] = *word++) == '\0') {
            line[cur-1] = ' ';
            line[cur] = '\0';
            break;
       }
    }
    
    space_available -= (word_len + 1);
    num_words ++;
} 

void  writeline(void) {
    int num_space = space_available + num_words ;
    char tmp[60 + 1];
    int line_count = 0;
    int i=0, j;
    while (num_words > 1) {
        while (1) {
            if((tmp[i++] = line[line_count++]) == ' ') {
                 int another_spaces = num_space/(num_words - 1) - 1;
                 j = 0;
                 for(;j<another_spaces;j++) {
                     tmp[i++] = ' ';
                 }
                 num_words --;
                 num_space -= (another_spaces + 1);
                 break;
            }
        }
    } 
    while( (tmp[i++] = line[line_count++]) != '\0');
    clearline();
    printf("%s\n", tmp);
    
}

int flushline(void) {
    int len = strlen(line); 
    if(len > 0)
        printf("%s\n", line);
    clearline();
    return 1;
}
