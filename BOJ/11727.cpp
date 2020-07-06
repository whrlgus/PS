#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int mod=1e4+7;
int s[1001]={0,1,3};

int main(){
	int n;cin>>n;
	f(i,3,n)s[i]=(s[i-1]+(s[i-2]<<1))%mod;
	cout<<s[n];
	return 0;
}
