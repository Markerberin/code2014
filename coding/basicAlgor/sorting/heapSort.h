#ifndef HEAP_SORT_H 
#define HEAP_SORT_H


void heapify(int a[],int cur,int last) {
	if(cur*2 +1 > last) return;
	if(cur*2+1 == last) {
		if(a[last] > a[cur]) { 
			swap(a,last,cur);
		}
		return;
	}
	int left = cur*2+1;
	int right = cur*2+2;
	int max = cur;
	if( a[right]> a[left] ) {
		if(a[right] > a[cur]) max = right;
	}
	else {
		if(a[left] > a[cur]) max = left;	
	}
	if(max == right || max == left) {
		swap(a,cur,max);
		heapify(a,max,last);
	}
	return;
}
int removeMax(int a[], int id) {
	int res = a[0];
	a[0] = a[id];
	heapify(a,0,id-1); 	
	return res;
}

void buildHeap(int a[],int last) {
	int s = (last-1)/2;
	for(int i= s;i>=0;i--) 
		heapify(a,i,last);
}
void heapSort(int a[],int n) {
	buildHeap(a,n-1);
	for(int i=n-1;i>0;i--) {
		a[i] = removeMax(a,i);
	}
}
#endif
