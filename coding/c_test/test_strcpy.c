#include<string.h> 
#include <stdlib.h> 
#include <stdio.h> 

int main () { 
	char name[64] = {0};
	strcpy(name, "test string.");
	printf("name : %s\n", name);
    printf("string len is : %d\n", strlen(name));
    printf("the very last :%d\n",name[strlen(name)]);
	return 0;
}
