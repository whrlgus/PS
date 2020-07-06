#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

long long s[68]={1,1,2,4};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	f(i,4,67)s[i]=s[i-1]+s[i-2]+s[i-3]+s[i-4];
	
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		cout<<s[n]<<'\n';
	}
	return 0;
}
