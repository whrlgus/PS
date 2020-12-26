#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int INF=1e5+1;
int n,m,k,s[101][10001];
struct info{ int v,c,d; };
vector<info> edge[101];

int sol(){
	queue<info> q;
	q.push({1,0,0});
	s[1][0]=0;
	
	int ret=INF;
	while(!q.empty()){
		info tmp=q.front();q.pop();
		
		if(tmp.v==n){
			ret=min(ret,tmp.d);
			continue;
		}
		if(s[tmp.v][tmp.c]<tmp.d)continue;
		
		for(info &p:edge[tmp.v]){
			int nc=p.c+tmp.c,nd=p.d+tmp.d;
			if(nc>m||s[p.v][nc]<=nd)continue;
			f(i,nc,m){
				if(s[p.v][i]>nd)s[p.v][i]=nd;
				else break;
			}
			q.push({p.v,nc,nd});
		}
	}
	
	return ret;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;cin>>t;
	while(t--){
		cin>>n>>m>>k;
		f(i,1,n){
			edge[i].clear();
			f(j,0,m)s[i][j]=INF;
		}
	
		f(i,1,k){
			int u,v,c,d;cin>>u>>v>>c>>d;
			edge[u].push_back({v,c,d});
		}
		int ans=sol();
		if(ans==INF)cout<<"Poor KCM\n";
		else cout<<ans<<'\n';
	}
	
	return 0;
}
