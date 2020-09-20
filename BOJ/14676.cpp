#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MX=1e5+1;
int n,m,k,x,y,a[MX],b[MX],cnt[MX];
vector<int> adj[MX];

bool sol(){
	while(k--){
		cin>>x>>y;
		if(x==1){
			if(a[y]!=b[y])return false;
			if(++cnt[y]==1)for(int v:adj[y])++b[v];
		}else{
			if(--cnt[y]==-1)return false;
			if(cnt[y]==0)for(int v:adj[y])--b[v];
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	while(m--){
		cin>>x>>y;
		adj[x].push_back(y);
		++a[y];
	}
	cout<<(sol()?"King-God-Emperor":"Lier!");
	
	return 0;
}
