#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

long long getPrice(int h,vector<vector<int>> &land, int P, int Q){
	long long sum=0;
	f(i,0,land.size())f(j,0,land.size()){
		long long diff=h-land[i][j];
		sum+=(diff>0?diff*P:-diff*Q);
	}
	return sum;
}

long long solution(vector<vector<int>> land, int P, int Q) {
	int l=0,r=1e9;
	while(l<r){
		int m=(l+r)/2;
		if(getPrice(m,land,P,Q)<getPrice(m+1,land,P,Q))r=m;
		else l=m+1;
	}
	return getPrice(r,land,P,Q);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	cout<<solution({{1, 2}, {2, 3}},3,2);
	int a=1e9;
	cout<<solution({{a,0},{a,a}},3,2);
	return 0;
}
