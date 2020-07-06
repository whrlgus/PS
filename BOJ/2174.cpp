#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int MAXN=101;
int A,B,N,M,board[MAXN][MAXN],com[MAXN][3],dy[]={1,0,-1,0},dx[]={0,1,0,-1};
struct info{int x,y,d;}robot[MAXN];

bool move(int no){
	info &r=robot[no];
	int nx=r.x+dx[r.d],ny=r.y+dy[r.d];
	if(nx<1||ny<1||nx>A||ny>B){
		cout<<"Robot "<<no<<" crashes into the wall";
		return false;
	}
	if(board[nx][ny]){
		cout<<"Robot "<<no<<" crashes into robot "<<board[nx][ny];
		return false;
	}
	board[r.x][r.y]=0;
	board[nx][ny]=no;
	r.x=nx;
	r.y=ny;
	return true;
}

bool run(){
	f(i,1,M){
		if(com[i][1]=='R') robot[com[i][0]].d=(robot[com[i][0]].d+com[i][2])%4;
		else if(com[i][1]=='L')robot[com[i][0]].d=(robot[com[i][0]].d-com[i][2]%4+4)%4;
		else while(com[i][2]--)if(!move(com[i][0]))return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>A>>B>>N>>M;
	char tmp;
	f(i,1,N){
		info &r=robot[i];
		cin>>r.x>>r.y>>tmp;
		if(tmp=='N')r.d=0;
		else if(tmp=='E')r.d=1;
		else if(tmp=='S')r.d=2;
		else r.d=3;
		board[r.x][r.y]=i;
	}
	f(i,1,M){
		cin>>com[i][0]>>tmp>>com[i][2];
		com[i][1]=tmp;
	}
	if(run())cout<<"OK";
	return 0;
}
