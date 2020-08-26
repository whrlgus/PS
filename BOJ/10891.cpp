#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MAXN=1e5+1;
int n,m,p[MAXN],cnt[MAXN];
vector<int> edge[MAXN];

void dfs(int u){
	++cnt[u];
	for(int v:edge[u])if(v!=p[u]&&cnt[v]!=2){
		if(cnt[v]){
			int tmp=u;
			while(tmp!=p[v]){
				if(++cnt[tmp]>2){
					cout<<"Not cactus";
					exit(0);
				}
				tmp=p[tmp];
			}
		}else{
			p[v]=u;
			dfs(v);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	while(m--){
		int a,b;cin>>a>>b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs(1);
	cout<<"Cactus";
	
	return 0;
}
