#include <stdio.h> 
#include <stdlib.h> 

int main () {
    int hex = 0x23456789;
    char * var = (char*) &hex;
    printf("%x\n", hex);
    printf("%hhx %hhx %hhx %hhx \n", var[0], var[1], var[2], var[3]);
    printf("%p %p\n",&var[0],&var[1]);
    return 0;
}
