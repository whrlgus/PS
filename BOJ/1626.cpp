#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
#define fr(i,l,r) for(int i=l;i>=r;--i)
using namespace std;

const int MAXV=50001;

bool foundMST;
int V,E,p[MAXV],sum,s[MAXV][17],d[MAXV],w[MAXV];
struct edge{
	int u,v,w;
	bool operator<(const edge &oth)const{
		return w>oth.w;
	}
};

struct info{
	int v,w;
};

priority_queue<edge> pq;
queue<edge> unselected;
vector<info> tree[MAXV];

int root(int x){
	return p[x]<0?x:p[x]=root(p[x]);
}

void findMst(){
	int cnt=V-1;
	while(!pq.empty()){
		edge tmp=pq.top();pq.pop();
		if(cnt==0){
			foundMST=true;
			unselected.push(tmp);
			continue;
		}
		int ru=root(tmp.u),rv=root(tmp.v);
		if(ru!=rv){
			p[ru]=rv;
			sum+=tmp.w;
			tree[tmp.u].push_back({tmp.v,tmp.w});
			tree[tmp.v].push_back({tmp.u,tmp.w});
			--cnt;
		}else unselected.push(tmp);
	}
}

void dfs(int u,int depth){
	d[u]=depth;
	f(i,1,17)s[u][i]=s[s[u][i-1]][i-1];
	for(info &tmp:tree[u])if(s[u][0]!=tmp.v){
		s[tmp.v][0]=u;
		w[tmp.v]=tmp.w;
		dfs(tmp.v,depth+1);
	}
}


int lca(int a, int b){
	if(d[a]<d[b])swap(a,b);
	fr(i,16,0)if(d[a]-d[b]>=(1<<i))a=s[a][i];
	if(a==b)return a;
	fr(i,16,0)if(s[a][i]!=s[b][i])a=s[a][i],b=s[b][i];
	return s[a][0];
}

int maxWeight(int from,int to,int mn){
	int mx=-1;
	while(from!=to){
		if(w[from]<mn)mx=max(mx,w[from]);
		from=s[from][0];
	}
	return mx;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>V>>E;
	f(i,0,E){
		int u,v,w;cin>>u>>v>>w;
		pq.push({u,v,w});
	}

	memset(p,-1,sizeof(p));
	findMst();
	if(!foundMST){
		cout<<-1;
		return 0;
	}
	memset(p,-1,sizeof(p));
	dfs(1,0);

	int mn=100001;
	while(!unselected.empty()){
		edge tmp=unselected.front();unselected.pop();
		int to=lca(tmp.u,tmp.v);
		int a=maxWeight(tmp.u,to,tmp.w),b=maxWeight(tmp.v,to,tmp.w);
		if(a<0&&b<0)continue;
		mn=min(mn,tmp.w-max(a,b));
	}
	if(mn==100001)cout<<-1;
	else cout<<sum+mn;
	return 0;
}


