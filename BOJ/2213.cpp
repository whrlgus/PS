#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int MAXN=1e4+1;
bool vis[MAXN];
int n,w[MAXN],s[MAXN][2];
vector<int> edge[MAXN],subset;

int getMax(int v,int k){//k는 포함여부
	int &ref=s[v][k];
	if(ref!=-1)return ref;
	
	ref=k?w[v]:0;
	for(int u:edge[v])if(!vis[u]){
		vis[u]=true;
		ref+=max(getMax(u,0),(k?0:getMax(u,1)));
		vis[u]=false;
	}
	
	return ref;
}

void findSub(int v, int k){
	if(k==1)subset.push_back(v);
	for(int u:edge[v])if(!vis[u]){
		int a=s[u][0],b=k?0:s[u][1];
		vis[u]=true;
		findSub(u, a<b);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,1,n)cin>>w[i];
	f(i,2,n){
		int a,b;cin>>a>>b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	edge[0].push_back(1);
	
	memset(s,-1,sizeof(s));
	
	cout<<getMax(0,0)<<'\n';
	findSub(0,0);
	sort(subset.begin(),subset.end());
	for(int v:subset)cout<<v<<" ";
	
	return 0;
}
