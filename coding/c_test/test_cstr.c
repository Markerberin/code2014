#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void f(char * s) {
	printf("str is: %s\n",s);
}

int main() {
   f("f*ck.");
   return 0;
}
