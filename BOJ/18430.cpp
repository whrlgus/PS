#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n,m,k[5][5],di[4][2]={{0,1},{0,-1},{-1,0},{1,0}},dj[4][2]={{-1,0},{-1,0},{0,1},{0,1}};
bool used[5][5];

bool isInBoundary(int i,int j){
	return 0<=i&&i<n&&0<=j&&j<m;
}

bool isValid(int ni[],int nj[]){
	f(t,0,2)if(!isInBoundary(ni[t],nj[t])||used[ni[t]][nj[t]])return false;
	return true;
}

int sol(int i, int j){
	if(i==n)return 0;
	if(j==m)return sol(i+1,0);
	if(used[i][j])return sol(i,j+1);
	int ret=sol(i,j+1),tmp=2*k[i][j];
	used[i][j]=true;
	f(d,0,4){
		int ni[2],nj[2];
		f(t,0,2)ni[t]=i+di[d][t],nj[t]=j+dj[d][t];
		if(!isValid(ni,nj))continue;
		
		int val=tmp;
		f(t,0,2)used[ni[t]][nj[t]]=true,val+=k[ni[t]][nj[t]];
		ret=max(ret,sol(i,j+1)+val);
		f(t,0,2)used[ni[t]][nj[t]]=false;
	}
	used[i][j]=false;
	return ret;
}

int main(){
	cin>>n>>m;
	f(i,0,n)f(j,0,m)cin>>k[i][j];
	cout<<sol(0,0);
	return 0;
}
