#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MXN=5e5;
int p[MXN];

int root(int x){
	return p[x]<0?x:p[x]=root(p[x]);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;cin>>n>>m;
	memset(p,-1,sizeof(p));
	f(i,0,m){
		int a,b;cin>>a>>b;
		int ra=root(a),rb=root(b);
		if(ra!=rb) p[rb]=ra;
		else cout<<i+1,exit(0);
	}
	cout<<0;
	return 0;
}
