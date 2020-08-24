#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MAXN=1e5;
int a[MAXN][3],b[MAXN],p[MAXN];

struct edge{
	int u,v,w;
	bool operator<(const edge& oth)const{
		return w<oth.w;
	}
};

int root(int x){
	return p[x]<0?x:p[x]=root(p[x]);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	f(i,0,n)cin>>a[i][0]>>a[i][1]>>a[i][2],b[i]=i;
	
	vector<edge> edges;
	f(i,0,3){
		sort(b,b+n,[i](int s, int t) { return a[s][i] < a[t][i]; });
		f(j,1,n)edges.push_back({b[j-1],b[j],abs(a[b[j-1]][i]-a[b[j]][i])});
	}
	sort(edges.begin(),edges.end());
	
	memset(p,-1,sizeof(p));
	
	int ans=0;
	for(edge &e:edges){
		int ru=root(e.u), rv=root(e.v);
		if(ru!=rv){
			p[ru]=rv;
			ans+=e.w;
			if(--n==1)break;
		}
	}
	cout<<ans;
	
	return 0;
}
