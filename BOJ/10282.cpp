#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n,d,c;cin>>n>>d>>c;
		vector<pair<int,int>> edge[10001];
		while(d--){
			int a,b,s;cin>>a>>b>>s;
			edge[b].push_back({a,s});
		}
		
		int sum=0,cnt=0,p[10001];
		bool vis[10001]{};
		f(i,1,n)p[i]=1e7;
		priority_queue<pair<int,int>> q;
		q.push({0,c});
		while(!q.empty()){
			int u=q.top().second,t=-q.top().first;q.pop();
			if(vis[u])continue;
			vis[u]=true;
			++cnt;
			sum=t;
			for(auto &tmp:edge[u]){
				int nt=t+tmp.second;
				if(p[tmp.first]>nt){
					p[tmp.first]=nt;
					q.push({-nt,tmp.first});
				}
			}
		}
		
		cout<<cnt<<' '<<sum<<'\n';
	}
	return 0;
}
