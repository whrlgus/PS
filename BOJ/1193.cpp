#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int x;cin>>x;
	int i=1,j=1;
	while(j<x)j+=(++i);
	
	int k=j-x,a=1+k,b=i-k;
	if(i&1)cout<<a<<'/'<<b;
	else cout<<b<<'/'<<a;
	return 0;
}
