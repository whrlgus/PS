#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int INF=10;
int n,m,no,a[11][11],b[11][11],dist[7][7],p[7],di[]={0,0,1,-1},dj[]={1,-1,0,0};
bool vis[11][11];
struct foo{
	int u,v,dist;
	bool operator<(const foo& oth)const{
		return dist>oth.dist;
	}
};

bool isInBoundary(int i,int j){
	return i>0&&j>0&&i<=n&&j<=m;
}

void assignNum(int i,int j){
	b[i][j]=no;
	f(d,0,3){
		int ni=i+di[d],nj=j+dj[d];
		if(isInBoundary(ni, nj)&&a[ni][nj]&&!b[ni][nj])assignNum(ni, nj);
	}
}

void calcDist(int i, int j){
	vis[i][j]=true;
	int &u=b[i][j];
	f(d,0,3){
		int ni=i,nj=j,len=-1;
		do{
			++len;
			ni+=di[d];
			nj+=dj[d];
		}while(isInBoundary(ni, nj)&&!a[ni][nj]);
		if(len>1&&isInBoundary(ni, nj)){
			int &v=b[ni][nj];
			if(u!=v)dist[u][v]=dist[v][u]=min(dist[u][v],len);
		}
	}
}

int find(int x){
	return p[x]<0?x:p[x]=find(p[x]);
}

int mst(){
	int ret=0,cnt=0;
	priority_queue<foo> pq;
	f(i,1,no)f(j,1,no)if(dist[i][j]!=INF)pq.push({i,j,dist[i][j]});
	memset(p,-1,sizeof(p));
	
	while(!pq.empty()){
		foo tmp=pq.top();pq.pop();
		int ru=find(tmp.u),rv=find(tmp.v);
		if(ru==rv)continue;
		p[rv]=ru;
		ret+=tmp.dist;
		if(++cnt==no-1)break;
	}
	return cnt==no-1?ret:-1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	f(i,1,n)f(j,1,m)cin>>a[i][j];
	f(i,1,n)f(j,1,m)if(a[i][j]&&!b[i][j])++no,assignNum(i,j);
	f(i,1,no)f(j,1,no)dist[i][j]=INF;
	f(i,1,n)f(j,1,m)if(a[i][j]&&!vis[i][j])calcDist(i, j);
	cout<<mst();
	
	return 0;
}


