#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int s[31]={0,1,3};

int sol(){
	int n;cin>>n;
	if(n==1)return 1;
	f(i,3,n)s[i]=s[i-1]+(s[i-2]<<1);
	return (s[n]+(n&1?s[n>>1]:s[(n>>1) + 1]))>>1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout<<sol();
	return 0;
}
