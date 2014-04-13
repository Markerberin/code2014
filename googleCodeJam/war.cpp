#include<iostream> 
#include<stdio.h> 
#include<algorithm>

using namespace std;
int solve_dwar(double *naomi,double * ken, int n) {
    int result = 0;
    int ke= n-1;
    int ni = 0,ki = 0;
    for(;ni<n;ni++) {
    	if(naomi[ni] > ken[ki]) {
	    result ++;
	    ki++;
	}
    }
    return result;
}
int solve_war(double *naomi,double *ken,int n) {
    int result = 0;
    int ni= 0;
    for(int i=0;i<n;i++) {
    	if(ken[i] > naomi[ni]) {result++;ni++;}
    }
    return n-result;
}
int main() {
    int T;
    cin >> T;
    for(int i=0 ; i<T; ++i) {
        int n,war,dwar;
	double x;
	cin >> n;
        double naomi[n];
	double ken[n];
	for (int j=0;j<n;++j) {
	    cin >> x;
	    naomi[j]= x;
	}

	for (int j=0;j<n;++j) {
	    cin >> x;
	    ken[j]= x;
	}
	sort(naomi,naomi+n);
 	sort(ken,ken+n);
	dwar = solve_dwar(naomi,ken,n);
	war = solve_war(naomi,ken,n);
	cout<<"Case #"<<i+1<<": "<<dwar<<" "<<war<<endl;
    }
    return 0;
}
