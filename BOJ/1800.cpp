#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;
typedef pair<int,int> pii;

int n,p,k,s[1001][1001];
vector<pii> edge[1001];
bool vis[1001];
struct info {
	int u,d,k;
	bool operator<(const info &oth) const{
		return d>oth.d;
	}
};

int sol(){
	priority_queue<info> pq;
	pq.push({1,0,k});
	s[1][k]=0;
	
	while(!pq.empty()){
		info tmp=pq.top();pq.pop();
		if(tmp.u==n)return s[n][tmp.k];
		
		for(auto ele:edge[tmp.u]){
			int nk=tmp.k-1;
			if(tmp.k>0&&s[ele.first][nk]>tmp.d){
				s[ele.first][nk]=tmp.d;
				pq.push({ele.first,tmp.d,nk});
			}
			int nd=max(tmp.d,ele.second);
			if(s[ele.first][tmp.k]>nd){
				s[ele.first][tmp.k]=nd;
				pq.push({ele.first,nd,tmp.k});
			}
		}
	}
	
	
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>p>>k;
	while(p--){
		int a,b,c;cin>>a>>b>>c;
		edge[a].push_back({b,c});
		edge[b].push_back({a,c});
	}
	for(int i=1;i<=n;++i)for(int j=0;j<=k;++j)s[i][j]=1e6;
	
	cout<<sol();
	return 0;
}
