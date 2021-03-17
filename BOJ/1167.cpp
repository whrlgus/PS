#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;
typedef pair<int,int> pii;
const int MAXV=1e5+1;
int V,ans;
vector<pii> edge[MAXV];

int sol(int i,int p){
	int mx=0;
	for(auto &ele:edge[i])if(ele.first!=p){
		int tmp=sol(ele.first,i)+ele.second;
		ans=max(ans,mx+tmp);
		mx=max(mx,tmp);
	}
	return mx;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>V;
	f(i,1,V){
		int a;cin>>a;
		while(1){
			int b;cin>>b;
			if(b==-1)break;
			int c;cin>>c;
			edge[a].push_back({b,c});
		}
	}
	sol(1,0);
	cout<<ans;
	return 0;
}
