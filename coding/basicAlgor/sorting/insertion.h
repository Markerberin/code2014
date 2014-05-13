#ifndef INSERTION_H
#define INSERTION_H


void insertionSort(int a[],int n) {
	if(n <= 1) return;
    for(int i=1;i<n;i++) {
		int tmp = a[i];
        int j;
		for(j=i-1;j>=0;j--) {
		    if(tmp < a[j]) {
				a[j+1]=a[j];
			}
			else break;
        }  	
		a[j+1] = tmp;
	} 
}
#endif
