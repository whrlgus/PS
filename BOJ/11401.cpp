#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MOD=1e9+7;

int power(int a,int b){
	int ret=1;
	while(b){
		if(b&1)ret=(1l*ret*a)%MOD;
		a=(1l*a*a)%MOD;
		b>>=1;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,k;cin>>n>>k;
	if(n<k*2)k=n-k;
	int a=1,b=1;
	f(i,0,k){
		a=(1l*a*(n-i))%MOD;
		b=(1l*b*(1+i))%MOD;
	}
	cout<<(1l*a*power(b,MOD-2))%MOD;
		  
	return 0;
}
