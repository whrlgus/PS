#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MXN=15,INF=-15000;
int n,t[MXN],p[MXN],s[MXN][2];

int sol(int i, int j){
	if(i>n)return INF;
	if(i==n)return 0;
	int &ref=s[i][j];
	if(ref!=-1)return ref;
	int val=j?p[i]:0;
	int ni=i+(j?t[i]:1);
	return ref=val+max(sol(ni,0),sol(ni,1));
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n;
	f(i,0,n)cin>>t[i]>>p[i];
	memset(s,-1,sizeof(s));
	
	cout<<max(sol(0,0),sol(0,1));
	
	return 0;
}
