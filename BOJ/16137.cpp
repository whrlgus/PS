#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n,m,a[10][10],di[]={-1,0,1,0,-1},dj[]={0,1,0,-1,0};
bool vis[10][10][2];
struct info{int i,j,k;};

bool isValid(int i, int j){
	return i>=0&&j>=0&&i<n&&j<n;
}

bool canBuild(int i,int j){
	f(d,0,4){
		int ni=i+di[d],nj=j+dj[d];
		if(!isValid(ni,nj)||a[ni][nj])continue;
		ni=i+di[d+1],nj=j+dj[d+1];
		if(!isValid(ni,nj)||a[ni][nj])continue;
		return false;
	}
	return true;
}

int sol(){
	queue<info> q;
	q.push({0,0,1});
	vis[0][0][1]=true;
	int t=1;
	while(!q.empty()){
		int size=q.size();
		while(size--){
			info u=q.front();q.pop();
			
			f(d,0,4){
				int ni=u.i+di[d],nj=u.j+dj[d];
				if(!isValid(ni,nj)||(a[u.i][u.j]>1&&(a[ni][nj]>1||a[ni][nj]==0)))continue;
				
				if(ni==n-1&&nj==n-1)return t;
				
				info v{-1};
				if(a[ni][nj]){
					if(t%a[ni][nj]==0)v={ni,nj,u.k};
					else v={u.i,u.j,u.k};
				}else if(canBuild(ni,nj)&&u.k){
					if(t%m==0)v={ni,nj,0};
					else v={u.i,u.j,1};
				}
				
				if(v.i!=-1){
					if((v.i!=u.i||v.j!=u.j)&&vis[v.i][v.j][v.k])continue;
					q.push(v);
					vis[v.i][v.j][v.k]=true;
				}
			}
		}
		++t;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	f(i,0,n)f(j,0,n)cin>>a[i][j];
	cout<<sol();
	
	return 0;
}
