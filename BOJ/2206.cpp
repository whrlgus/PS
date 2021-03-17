#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int N,M,di[]={0,0,-1,1},dj[]={-1,1,0,0};
char B[1000][1001];
bool vis[1000][1000][2];
struct info{int i,j,k;};

int sol(){
	queue<info> q;
	q.push({N-1,M-1,0});
	int ans=1;
	while(!q.empty()){
		++ans;
		int size=q.size();
		while(size--){
			info tmp=q.front();q.pop();
			f(d,0,4){
				int ni=tmp.i+di[d],nj=tmp.j+dj[d];
				if(ni<0||nj<0||ni>=N||nj>=M)continue;
				int nk=(B[ni][nj]=='1')+tmp.k;
				if(nk>1||vis[ni][nj][nk])continue;
				if(!ni&&!nj)return ans;
				vis[ni][nj][nk]=true;
				q.push({ni,nj,nk});
			}
		}
	}
	
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N>>M;
	f(i,0,N)cin>>B[i];
	cout<<(N==1&&M==1?1:sol());
	return 0;
}
