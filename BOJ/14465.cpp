#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int N=1e5+1;
int n,k,b,s[N];
bool p[N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k>>b;
	while(b--){
		int tmp;cin>>tmp;
		p[tmp]=true;
	}
	
	f(i,1,k)s[i]=(!p[i])+s[i-1];
	int mx=p[k];
	f(i,k+1,n){
		s[i]=(!p[i])+s[i-1]-(!p[i-k]);
		mx=max(mx,s[i]);
	}
	
	cout<<k-mx;
	
	return 0;
}
