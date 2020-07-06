#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int MAXN=4001;
vector<int> adj[MAXN];
int dist[MAXN],p;
bool vis[MAXN];

bool foo(int prev,int curr){
	vis[curr]=true;
	for(int next:adj[curr])if(next!=prev){
		if(vis[next]){
			dist[next]=0;
			p=next;
			return true;
		}
		if(foo(curr,next)&&next!=p){
			dist[next]=0;
			return true;
		}
	}
	return false;
}

void boo(int prev, int curr){
	dist[curr]=dist[prev]+1;
	for(int next:adj[curr])if(dist[next]==-1)boo(curr,next);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	f(i,1,n){
		int a,b;cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	memset(dist, -1, sizeof(dist));
	foo(0, 1);
	f(i,1,n)if(dist[i]==0)for(int j:adj[i])if(dist[j]==-1)boo(i, j);
	f(i,1,n)cout<<dist[i]<<' ';
	return 0;
}
