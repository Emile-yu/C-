#include <iostream>
#include <stdlib.h>
using namespace std;
int p[4];
int max(int a, int b) {
	return a>b?a:b;
}

int memoized_cut_rod_aux(int* p, int n, int* r) {
	int res = -1;
	if(r[n] >= 0) return r[n];
	
	if(0 == n) res = 0;
	else {
		for(int i=0;i<n;i++) {
			res = max(res, p[i]+memoized_cut_rod_aux(p, n-i-1, r));
			cout<<"i = "<<i<<";res = "<<res<<endl;
		}	
	}
	r[n] = res;
	//cout<<"n = "<<n<<": "<<res<<endl;
	return res;
}

int memoized_cut_rod(int* p, int n) {
	int *r = (int *)calloc(n+1,sizeof(int));
	for(int i=0;i<=n;i++) {
		r[i] = -1;
	}
	return memoized_cut_rod_aux(p,n,r);	
}


int cut_rod(int *p,int n) {
	int q=-1;
	if(n==0) return 0;
	for(int i=0;i<n;i++) {
		q=max(q,p[i]+cut_rod(p,n-i-1));
	}
	return q;
}
int main() {
	int p[4] = {1,5,8,9};
	int res;
	//res = cut_rod(p,4);
	res = memoized_cut_rod(p,4);
	cout<<"res = "<<res<<endl;
	return 0;
}
