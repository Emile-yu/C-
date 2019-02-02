#include <iostream>
#include <stdlib.h>
using namespace std;
int p[4];
int max(int a, int b) {
	return a>b?a:b;
}

int memoized_cut_rod_bottom(int* p, int n) {
	int *r = (int *)calloc(n+1,sizeof(int));
	r[0]=0;
	int res = -1;
	int i,j;
	for(j=1;j<=n;j++) {//开始准备切割几段
		for(i=0;i<j;i++) {//在j的基础上,求解子问题
			res = max(res, p[i] + r[j-i-1]);//r[j-i]获得规模为j-i的子问题的结果
		}
		r[j] = res;
	}
	return res;
}

int main() {
	int p[4] = {1,5,8,9};
	int res;
	res = memoized_cut_rod_bottom(p,4);
	cout<<"res = "<<res<<endl;
	return 0;
}
