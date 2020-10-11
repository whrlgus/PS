#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int MXN=2e5+1;
int n,s[MXN][2],a[MXN];
vector<int> adj[MXN];

int sol(int i,int j){
	int &ref=s[i][j];
	if(ref!=-1)return ref;
	
	ref=0;
	for(int v:adj[i])ref+=sol(v,1);
	if(!j)return ref;
	int tmp=0;
	for(int v:adj[i])tmp=max(tmp,ref-s[v][1]+sol(v,0)+a[i]*a[v]);
	return ref=max(ref,tmp);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,2,n){
		int tmp;cin>>tmp;
		adj[tmp].push_back(i);
	}
	f(i,1,n)cin>>a[i];
	
	memset(s,-1,sizeof(s));
	cout<<sol(1,1);
	
	return 0;
}
