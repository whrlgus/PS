#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;
int n,m,di[]={1,-1,0,0},dj[]={0,0,1,-1};
char board[50][51];
bool edge[50][50][50][50],vis[50][50];

bool foo(int i,int j,int k){
	if(vis[i][j])return true;
	vis[i][j]=true;
	f(d,0,4){
		int ni=i+di[d],nj=j+dj[d];
		if(ni<0||nj<0||ni>=n||nj>=m||
		   board[ni][nj]!=board[i][j]||
		   edge[i][j][ni][nj]||edge[ni][nj][i][j])continue;
		edge[i][j][ni][nj]=edge[ni][nj][i][j]=true;
		if(foo(ni,nj,k+1))return true;
	}
	return false;
}

bool sol(){
	f(i,0,n)f(j,0,m)if(!vis[i][j]&&foo(i,j,1))return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	f(i,0,n)cin>>board[i];
	cout<<(sol()?"Yes":"No");
	return 0;
}
