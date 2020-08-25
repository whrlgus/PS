#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n,a[125][125],di[]={0,0,-1,1},dj[]={1,-1,0,0};
bool vis[125][125];

struct info{
	int i,j,w;
	bool operator<(const info &oth)const{
		return w>oth.w;
	}
};

int sol(){
	priority_queue<info> pq;
	pq.push({0,0,a[0][0]});
	
	while(!pq.empty()){
		info tmp=pq.top();pq.pop();
		
		f(d,0,4){
			int ni=tmp.i+di[d],nj=tmp.j+dj[d];
			if(ni<0||ni>=n||nj<0||nj>=n||vis[ni][nj])continue;
			int nw=tmp.w+a[ni][nj];
			if(ni==n-1&&nj==n-1)return nw;
			vis[ni][nj]=true;
			pq.push({ni,nj,nw});
		}
	}
	
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc=0;
	while(cin>>n&&n){
		f(i,0,n)f(j,0,n)cin>>a[i][j],vis[i][j]=false;
		cout<<"Problem "<<++tc<<": "<<sol()<<'\n';
	}
	return 0;
}
