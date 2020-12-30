#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MXN=3e5+1;
int n,m,k,x,d[MXN];
vector<int> edge[MXN];

void sol(){
	int dist=0;
	queue<int> q;
	q.push(x);
	d[x]=0;
	while(!q.empty()&&dist<k){
		int size=q.size();
		while(size--){
			int u=q.front();q.pop();
			for(int v:edge[u])if(d[v]==-1){
				q.push(v);
				d[v]=dist;
			}
		}
		++dist;
	}
	
	if(q.empty()){
		cout<<-1;
		return;
	}
	vector<int> ans;
	while(!q.empty()){
		ans.push_back(q.front());
		q.pop();
	}
	sort(ans.begin(),ans.end());
	for(int u:ans)cout<<u<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m>>k>>x;
	f(i,0,m){
		int a,b;cin>>a>>b;
		edge[a].push_back(b);
	}
	memset(d,-1,sizeof(d));
	sol();

	return 0;
}
