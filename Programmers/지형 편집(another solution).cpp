#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

long long solution(vector<vector<int>> land, int P, int Q) {
	int h[90000],n=0;
	f(i,0,land.size())f(j,0,land.size())h[n++]=land[i][j];
	sort(h,h+n);
	
	long long price=0,ans;
	f(i,1,n)price+=(long long)(h[i]-h[0])*Q;
	ans=price;
	f(i,1,n){
		price+=(long long)i*(h[i]-h[i-1])*P;
		price-=(long long)(n-i)*(h[i]-h[i-1])*Q;
		ans=min(ans,price);
	}
	return ans;
}
