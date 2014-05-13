#include<stdio.h>
#include <stdlib.h> 
#include <iostream> 
#include <math.h>
#include <string.h> 
#include <time.h> 
#include "insertion.h"
#include "selection.h"
#include "mergeSort.h"
#include "heapSort.h"
#include "quickSort.h"
using namespace std;

void printArr(int a[],int n) {
	
    for(int i=0;i<n;i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main (int argc, char * argv[]) {
    printf("Please enter the length of array to be generate: \n");
	int n;
    scanf("%d",&n);
    int a[n];
	clock_t t;
    srand(time(NULL));
    for(int i=0;i<n;i++) {
    	a[i] = rand()%1000;
	}
	if(argc > 1) {
		if(!strncmp(argv[1],"insert",6))  {
			t = clock();
    		insertionSort(a, n);
			t = clock() - t;
			printf("It took insertionSort %ld clicks\n",t);
		}else if(!strncmp(argv[1],"select",6)) {
			t = clock();
			selectionSort(a,n);
			t = clock() - t;
			printf("It took selectionSort %ld clicks\n",t);
		}
		else if(!strncmp(argv[1],"merge",5)){
		
			t = clock();
			mergeSort(a,n);
			t = clock() - t;
			printf("It took mergeSort %ld clicks\n",t);
		}
		else if(!strncmp(argv[1], "quick", 5)) {
			t = clock();
			quickSort(a,n);
			t = clock() -t ;
			printf("It took quickSort %ld clicks\n",t);
		}
		else {
			t = clock();
			heapSort(a,n);
			t = clock() - t;
			printf("It took heapsort %ld clicks\n",t);
		}
	}
	/*
	t = clock();
    insertionSort(a, n);
	t = clock() - t;
	printf("It took insertionSort %ld clicks\n",t);
	
	t = clock();
	selectionSort(a,n);
	printArr(a,n);
	t = clock() - t;
	printf("It took selectionSort %ld clicks\n",t);
	*/

	return 0;
}
