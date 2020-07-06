#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int N,M,di[]={0,-1,0,1},dj[]={-1,0,1,0};
char maze[7][8];
bool vis[7][7][1<<7][1<<7];
struct info{int i,j,h,v;};

bool isValid(char typeA,char typeB,int d){
	if(typeA=='B'||typeB=='B')return false;
	return !(d&1?(typeA=='D'||typeB=='D'):(typeA=='C'||typeB=='C'));
}

char getType(int i,int j,int h,int v){
	if(maze[i][j]<='B'||!(((h>>i)&1)^((v>>j)&1)))return maze[i][j];
	return maze[i][j]=='C'?'D':'C';
}

int sol(){
	queue<info> q;
	q.push({0,0,0,0});
	vis[0][0][0][0]=true;
	
	int sec=0;
	while(!q.empty()){
		int size=q.size();
		while(size--){
			int i=q.front().i,j=q.front().j,h=q.front().h,v=q.front().v;q.pop();
			if(i==N-1&&j==M-1)return sec;
			
			int nh=(1<<i)^h,nv=(1<<j)^v;
			if(!vis[i][j][nh][nv]){
				q.push({i,j,nh,nv});
				vis[i][j][nh][nv]=true;
			}
			char typeA=getType(i,j,h,v);
			f(d,0,4){
				int ni=i+di[d],nj=j+dj[d];
				if(ni<0||nj<0||ni>=N||nj>=M||vis[ni][nj][h][v])continue;
				if(isValid(typeA,getType(ni,nj,h,v),d)){
					q.push({ni,nj,h,v});
					vis[ni][nj][h][v]=true;
				}
			}
		}
		++sec;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N>>M;
	f(i,0,N)cin>>maze[i];
	cout<<sol();
	return 0;
}

