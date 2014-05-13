#ifndef MERGE_SORT_H
#define MERGE_SORT_H

void merge(int a[],int s,int mid,int end ) {
	int bn = mid-s+1; int cn= end-mid;
	int bi = 0, ci = 0; 
	int b[mid-s+1]; int c[end-mid];
	memcpy(b,a+s,(mid-s+1)*4);
	memcpy(c,a+mid+1,(end-mid)*4);
	while(bi< bn && ci < cn) {
		if(b[bi]<c[ci]) a[s++] = b[bi++];
		else a[s++] = c[ci++];
	}
	while(bi<bn) a[s++] = b[bi++];
	while(ci<cn) a[s++] = c[ci++];
}
void mergesort(int a[],int s,int e) {
	if(s < e) {
		int mid = s+ (e-s)/2;
		mergesort(a,s,mid);
		mergesort(a,mid+1,e);
		merge(a,s,mid,e);
	}
}
void mergeSort(int a[],int n) {
	if(n<=1) return;
	mergesort(a,0,n-1);
}
#endif
