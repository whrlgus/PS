#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;
int N,K,T[10][10],ans=1e4;
bool vis[10];

void foo(int n,int u,int val){
	if(ans<=val)return;
	if(n==N){
		ans=min(ans,val);
		return;
	}
	f(i,0,N)if(!vis[i]){
		vis[i]=true;
		foo(n+1,i,val+T[u][i]);
		vis[i]=false;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N>>K;
	f(i,0,N)f(j,0,N)cin>>T[i][j];
	f(k,0,N)f(i,0,N)f(j,0,N){
		int tmp=T[i][k]+T[k][j];
		if(T[i][j]>tmp)T[i][j]=tmp;
	}
	vis[K]=true;
	foo(1, K, 0);
	cout<<ans;
	return 0;
}
