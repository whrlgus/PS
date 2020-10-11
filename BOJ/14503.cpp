#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n,m,r,c,d,room[50][50],turn[]={3,0,1,2},back[]={2,3,0,1},di[]={-1,0,1,0},dj[]={0,1,0,-1},ans;
bool chk[50][50];

bool isValid(int i,int j){
	return 0<=i&&i<n&&0<=j&&j<m&&!room[i][j];
}

bool sol(){
	if(!chk[r][c]){
		chk[r][c]=true;
		++ans;
	}
	int nr,nc;
	f(k,0,4){
		d=turn[d];
		nr=r+di[d];
		nc=c+dj[d];
		
		if(isValid(nr,nc)&&!chk[nr][nc]){
			r=nr;
			c=nc;
			return true;
		}
	}
	int nd=back[d];
	nr=r+di[nd];
	nc=c+dj[nd];
	if(!isValid(nr,nc))return false;
	r=nr;
	c=nc;
	return true;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m>>r>>c>>d;
	f(i,0,n)f(j,0,m)cin>>room[i][j];
	
	while(sol());
	cout<<ans;
	
	return 0;
}
