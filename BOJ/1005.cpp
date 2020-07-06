#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
#define MAXN 1001
using namespace std;

int n,d[MAXN],s[MAXN];
bool e[MAXN][MAXN];

int sol(int i){
	if(s[i]!=-1)return s[i];
	int mx=0;
	f(j,1,n)if(e[i][j])mx=max(mx,sol(j));
	return s[i]=d[i]+mx;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;cin>>t;
	while(t--){
		memset(e, false, sizeof(e));
		memset(s, -1, sizeof(s));
		int k;
		cin>>n>>k;
		f(i,1,n)cin>>d[i];
		while(k--){
			int a,b;cin>>a>>b;
			e[b][a]=1;
		}
		int w;cin>>w;
		
		cout<<sol(w)<<'\n';
	}
	return 0;
}
