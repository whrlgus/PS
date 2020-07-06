#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

vector<bool> vis;
vector<vector<int>> s;

int fall(int x){
	vis[x]=true;
	int cnt=1;
	for(int y:s[x])if(!vis[y])cnt+=fall(y);
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n,m,l;cin>>n>>m>>l;
		vector<bool>(n+1,false).swap(vis);
		vector<vector<int>>(n+1).swap(s);
		while(m--){
			int x,y;cin>>x>>y;
			s[x].push_back(y);
		}
		int ans=0;
		while(l--){
			int z;cin>>z;
			if(!vis[z])ans+=fall(z);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
