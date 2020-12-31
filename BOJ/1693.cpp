#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int MXN=1e5+1,INF=2e6;
int n,s[MXN][20],size;
bool vis[MXN];
vector<int> edge[MXN];

int sol(int i,int j){
	int &ref=s[i][j];
	if(ref!=-1)return s[i][j];
	
	ref=0;
	for(int u:edge[i])if(!vis[u]){
		vis[u]=true;
		int tmp=INF;
		f(k,1,size)if(k!=j)tmp=min(tmp,sol(u,k));
		ref+=tmp;
		vis[u]=false;
	}
	return ref+=j;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,2,n){
		int a,b;cin>>a>>b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	size=log2(n)+1;
	memset(s,-1,sizeof(s));
	edge[0].push_back(1);
	cout<<sol(0,0);
	
	return 0;
}
