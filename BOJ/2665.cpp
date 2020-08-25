#include<cstdio>
#include<queue>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;
char a[50][51];
int n,s[50][50],di[]={0,0,-1,1},dj[]={-1,1,0,0};

struct info{int i,j,w;};

int sol(){
	queue<info> q;
	q.push({0,0,0});
	s[0][0]=0;
	
	while(!q.empty()){
		info tmp=q.front();q.pop();
		
		f(d,0,4){
			int ni=tmp.i+di[d],nj=tmp.j+dj[d];
			if(ni<0||ni>=n||nj<0||nj>=n)continue;
			int nw=tmp.w+(a[ni][nj]=='0'?1:0);
			if(s[ni][nj]<=nw)continue;
			s[ni][nj]=nw;
			q.push({ni,nj,nw});
		}
	}
	
	return s[n-1][n-1];
}

int main(){
	scanf("%d",&n);
	f(i,0,n){
		scanf("%s",a[i]);
		f(j,0,n)s[i][j]=2500;
	}
	printf("%d",sol());
	return 0;
}
