#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MOD=1e6;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	long long n;cin>>n;
	n%=(int)(15e5);
	if(n<2){
		cout<<n;
		return 0;
	}
	
	--n;
	int a=1,b=1;
	while(--n){
		int tmp=b;
		b=(a+b)%MOD;
		a=tmp;
	}
	cout<<b;
	return 0;
}
