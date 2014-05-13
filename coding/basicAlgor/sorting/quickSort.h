#ifndef QUICK_SORT_H
#define QUICK_SORT_H

int partition(int a[],int s,int e, int pivot) {
	int p = a[s+pivot];
	swap(a,s+pivot,e);
	int i = s,j = s;
	for(;i<e;i++) {
		if( a[i] <= p){
			swap(a,i,j);
			j++;
		} 
	}
    swap(a,e,j);
	return j;
}
void quicksort(int a[],int s,int e) {
	if(s < e) {
		int r = partition(a,s,e,rand()%(e-s+1));
		quicksort(a,s,r-1);
		quicksort(a,r+1,e);	
	}
}
void quickSort(int a[],int n) {
	if(n<=1) return ;
	quicksort(a,0,n-1);
}

#endif
