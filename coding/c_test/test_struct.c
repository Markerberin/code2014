#include <stdio.h> 
#include <stdlib.h> 

typedef struct sa_s {
    char a;
    short int b;
    char c;
} sa_t;


typedef struct sb_s {
    char b;
    char c;
    short int a;
} sb_t;


typedef struct sc_s {
    char a;
    int b;
} sc_t;


typedef struct sd_s {
    int  a;
    char b;
} sd_t;


typedef struct se_s {
    int  a;
    short int b;
} se_t;


typedef struct sf_s {
    short int b;
    int  a;
} sf_t;



int main (int argc, char * argv[]) {
    printf("argc = %d\n", argc);
    int i = argc;
    while(i > 0) {
        printf("argv[%d] = %s\n", argc-i,argv[argc-i]);
        i--;
    }
    printf("size of sa_t is %ld\n", sizeof(sa_t));
    printf("size of sb_t is %ld\n", sizeof(sb_t));
    printf("size of sc_t is %ld\n", sizeof(sc_t));
    printf("size of sd_t is %ld\n", sizeof(sd_t));
    printf("size of se_t is %ld\n", sizeof(se_t));
    printf("size of sf_t is %ld\n", sizeof(sf_t));
   
   
    return 0;
}
