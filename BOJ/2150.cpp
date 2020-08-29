// --kosaraju
//#include<bits/stdc++.h>
//#define f(i,l,r) for(int i=l;i<=r;++i)
//using namespace std;
//
//vector<vector<int>> scc,adj,rev;
//vector<int> order;
//bool vis[10001];
//
//void dfs(int a, vector<vector<int>> &adj, vector<int> &list){
//	vis[a]=true;
//	for(int b:adj[a])if(!vis[b])dfs(b,adj,list);
//	list.push_back(a);
//}
//
//int main(){
//	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//
//	int v,e;cin>>v>>e;
//	adj.assign(v+1, vector<int>());
//	rev.assign(v+1, vector<int>());
//	while(e--){
//		int a,b;cin>>a>>b;
//		adj[a].push_back(b);
//		rev[b].push_back(a);
//	}
//
//	f(i,1,v)if(!vis[i])dfs(i,adj,order);
//
//	reverse(order.begin(),order.end());
//
//	memset(vis,false,sizeof(vis));
//	for(int a:order)if(!vis[a]){
//		vector<int> list;
//		dfs(a,rev,list);
//		sort(list.begin(),list.end());
//		scc.push_back(list);
//	}
//
//	sort(scc.begin(),scc.end());
//	cout<<scc.size()<<'\n';
//	for(auto &list:scc){
//		for(int a:list)cout<<a<<' ';
//		cout<<"-1\n";
//	}
//
//	return 0;
//}

// --tarjan
#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int MAXV=1e4+1;

int v,e,t,tin[MAXV],low[MAXV],sta[MAXV],idx;
bool inSta[MAXV];
vector<int> adj[MAXV];
vector<vector<int>> scc;

void dfs(int a){
	tin[a]=low[a]=++t;
	sta[++idx]=a;
	inSta[a]=true;
	for(int b:adj[a]){
		if(!tin[b]){
			dfs(b);
			low[a]=min(low[a],low[b]);
		}
		else if(inSta[b])low[a]=min(low[a],tin[b]);
	}
	
	if(tin[a]==low[a]){
		vector<int> list;
		do{
			list.push_back(sta[idx]);
			inSta[sta[idx]]=false;
		}while(sta[idx--]!=a);
		sort(list.begin(),list.end());
		scc.push_back(list);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>v>>e;
	while(e--){
		int a,b;cin>>a>>b;
		adj[a].push_back(b);
	}
	f(i,1,v)if(!tin[i])dfs(i);
	
	sort(scc.begin(),scc.end());
	cout<<scc.size()<<'\n';
	for(auto &list:scc){
		for(int a:list)cout<<a<<' ';
		cout<<"-1\n";
	}
	return 0;
}
