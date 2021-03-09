#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int N,M,t[1<<18];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N>>M;
	f(i,0,N)cin>>t[i+N];
	for(int i=N-1;i>0;--i)t[i]=min(t[i<<1],t[i<<1|1]);
	while(M--){
		int a,b;cin>>a>>b;
		int mn=1e9;
		for(a+=(N-1),b+=N;a<b;a>>=1,b>>=1){
			if(a&1)mn=min(mn,t[a++]);
			if(b&1)mn=min(mn,t[--b]);
		}
		cout<<mn<<'\n';
	}
	return 0;
}
