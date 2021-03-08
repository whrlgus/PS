#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int N=1e5+1;
int n,s[N],t[N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,1,n)cin>>t[i]>>t[i]>>t[i];
	s[1]=t[1];
	f(i,2,n)s[i]=max(s[i-1],s[i-2]+t[i]);
	cout<<s[n];
	
	return 0;
}
