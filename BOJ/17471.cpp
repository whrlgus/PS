#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int MAXN=11;
const int INF=1e4;
int n,pop[MAXN],ans=INF;
bool con[MAXN][MAXN],dis[MAXN],vis[MAXN];

int count(int u){
	int ret=1;
	vis[u]=true;
	f(v,1,n)if(con[u][v]&&dis[v]==dis[u]&&!vis[v])ret+=count(v);
	return ret;
}

void sol(int i){
	if(i>n){
		memset(vis,false,sizeof(vis));
		int cnt_con[2]{},cnt_pop[2]{};
		f(i,1,n){
			if(!vis[i])cnt_con[dis[i]]=count(i);
			cnt_pop[dis[i]]+=pop[i];
		}
		if(cnt_con[0]+cnt_con[1]==n&&cnt_pop[0]&&cnt_pop[1])
			ans=min(ans,abs(cnt_pop[0]-cnt_pop[1]));
		return;
	}
	dis[i]=false;
	sol(i+1);
	dis[i]=true;
	sol(i+1);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,1,n)cin>>pop[i];
	f(i,1,n){
		int cnt;cin>>cnt;
		while(cnt--){
			int v;cin>>v;
			con[i][v]=true;
		}
	}
	ans=INF;
	sol(0);
	cout<<(ans==INF?-1:ans);
	return 0;
}
