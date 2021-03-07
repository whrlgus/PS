#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int INF=1e9;
struct info{
	int i,j,k,v;
	bool operator< (const info &oth) const{return v>oth.v;}
};
int n,t,b[100][100],s[100][100][3],di[]={0,0,-1,1},dj[]={-1,1,0,0};

int sol(){
	priority_queue<info> q;
	q.push({0,0,3,0});
	s[0][0][0]=s[0][0][2]=0;
	while(!q.empty()){
		info tmp=q.top();q.pop();
		if(tmp.i==n-1&&tmp.j==n-1)return tmp.v;
		
		int nk=tmp.k-1,nv=tmp.v+t;
		f(d,0,4){
			int ni=tmp.i+di[d],nj=tmp.j+dj[d];
			if(ni<0||nj<0||ni>=n||nj>=n)continue;
			int val=nv+(nk==0?b[ni][nj]:0);
			if(s[ni][nj][nk]<=val)continue;
			s[ni][nj][nk]=val;
			q.push({ni,nj,nk==0?3:nk,val});
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>t;
	f(i,0,n)f(j,0,n){
		cin>>b[i][j];
		f(k,0,3)s[i][j][k]=INF;
	}
	cout<<sol();
	
	return 0;
}

