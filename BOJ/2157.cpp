#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int INF=-3e6;
struct info{int u,c;};
vector<info> a[301];
int s[301][300];

int sol(int i,int j){
	if(j<0)return INF;
	if(i==1)return 0;
	int &ref=s[i][j];
	if(ref!=-1)return ref;
	
	ref=INF;
	for(info &in:a[i])ref=max(ref,sol(in.u,j-1)+in.c);
	return ref;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	f(i,0,k){
		int u,v,c;cin>>u>>v>>c;
		if(u<v)a[v].push_back({u,c});
	}
	memset(s, -1, sizeof(s));
	cout<<sol(n,m-1);
	return 0;
}
