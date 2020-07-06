#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;
int n,k,a[13][13],dr[]={0,0,0,-1,1},dc[]={0,1,-1,0,0};
bool finished;
vector<int> v[13][13];
struct info{
	int r,c,d;
	bool movable;
}h[11];

bool canMove(int r, int c){
	return r>0&&c>0&&r<=n&&c<=n&&a[r][c]!=2;
}

void move(int i, int nr, int nc){
	h[i].movable=false;
	vector<int> &prev=v[h[i].r][h[i].c], &curr=v[nr][nc];
	
	if(a[nr][nc])reverse(prev.begin(), prev.end());
	
	for(int &j:prev){
		curr.push_back(j);
		h[j].r=nr;
		h[j].c=nc;
	}
	prev.clear();
	h[curr[0]].movable=true;
	finished=curr.size()>3;
}

int sol(){
	f(t,1,1000)f(i,1,k)if(h[i].movable){
		int nr=h[i].r+dr[h[i].d],nc=h[i].c+dc[h[i].d];
		if(!canMove(nr, nc)){
			h[i].d+=(h[i].d&1?1:-1);
			nr=h[i].r+dr[h[i].d],nc=h[i].c+dc[h[i].d];
			if(canMove(nr, nc))move(i,nr,nc);
		}else move(i,nr,nc);
		if(finished)return t;
	}
	return -1;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	f(i,1,n)f(j,1,n)cin>>a[i][j];
	f(i,1,k){
		cin>>h[i].r>>h[i].c>>h[i].d;
		h[i].movable=true;
		v[h[i].r][h[i].c].push_back(i);
	}
	
	cout<<sol();
	return 0;
}
