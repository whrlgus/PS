#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
#define fr(i,l,r) for(int i=l;i>=r;--i)
using namespace std;

typedef pair<int,int> pii;
char b[8][9];
int di[]={0,0,-1,1,-1,-1,1,1,0},dj[]={-1,1,0,0,-1,1,-1,1,0};

void move(){
	fr(i,7,0)f(j,0,8)b[i+1][j]=b[i][j];
	f(i,0,8)b[0][i]='.';
}

bool sol(){
	queue<pii> q;
	q.push({7,0});
	
	while(!q.empty()){
		int size=q.size();
		set<pii> s;
		while(size--){
			pii tmp=q.front();q.pop();
			f(d,0,9){
				int ni=tmp.first+di[d],nj=tmp.second+dj[d];
				if(ni<0||nj<0||ni>=8||nj>=8||b[ni][nj]=='#')continue;
				if(ni==0&&nj==7)return true;
				s.insert({ni,nj});
			}
		}
		move();
		for(pii ele:s)if(b[ele.first][ele.second]!='#')q.push(ele);
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f(i,0,8)cin>>b[i];
	cout<<sol();
	return 0;
}
