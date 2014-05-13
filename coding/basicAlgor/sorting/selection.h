#ifndef SELECTION_H
#define SELECTION_H

void swap(int a[],int i,int j) {
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}
void selectionSort(int a[],int n) {
	if(n<=1) return;
	for(int i=0;i<n-1;i++) {
		int min = i ;int j = i+1;
		for(;j<n;j++) {
			if(a[j] <a[min]) min = j; 
		}
		swap(a,i,min);
	}
}
#endif
