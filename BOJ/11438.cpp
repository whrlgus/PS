#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
#define fr(i,l,r) for(int i=l;i>=r;--i)
using namespace std;

const int MAXN=100001,LOGN=18;

int n,m,s[MAXN][LOGN+1],d[MAXN],a,b;
vector<int> edge[MAXN];

void dfs(int u, int depth){
	d[u]=depth;
	for(int v:edge[u])if(v!=s[u][0]){
		s[v][0]=u;
		f(k,1,LOGN)s[v][k]=s[s[v][k-1]][k-1];
		dfs(v,depth+1);
	}
}



int lca(int a,int b){
    if(d[a]<d[b])swap(a,b);
    fr(k,LOGN,0)if(d[a]-d[b]>=(1<<k))a=s[a][k];
    if(a==b)return a;
    fr(k,LOGN,0)if(s[a][k]!=s[b][k])a=s[a][k],b=s[b][k];
    return s[a][0];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n;
	f(i,2,n){
		cin>>a>>b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	dfs(1,0);
	
	cin>>m;
	while(m--){
		cin>>a>>b;
		cout<<lca(a,b)<<'\n';
	}
	
	return 0;
}
