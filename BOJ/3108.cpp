#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int n,p[1001],s[1001][1001];
bool vis[1001];

int root(int x){
	return p[x]?p[x]=root(p[x]):x;
}

void foo(int i,int &ref){
	if(ref){
		int ra=root(ref),rb=root(i);
		if(ra!=rb)p[rb]=ra;
	}else ref=i;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,1,n){
		int pos[4];
		cin>>pos[0]>>pos[2]>>pos[1]>>pos[3];
		f(j,0,3)pos[j]+=500;
		
		f(x,pos[0],pos[1])f(k,2,3)foo(i,s[x][pos[k]]);
		f(y,pos[2],pos[3])f(k,0,1)foo(i,s[pos[k]][y]);
	}
	
	int cnt=s[500][500]?-1:0;
	f(i,1,n){
		int r=root(i);
		if(!vis[r])++cnt,vis[r]=true;
	}
	cout<<cnt;
	return 0;
}
