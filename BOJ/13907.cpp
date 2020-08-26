#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int n,m,k,s,d,t[1001],chk[1001],idx;
struct info{
	int u,w,cnt;
	bool operator<(const info &oth)const{
		return w>oth.w;
	}
};

vector<pair<int,int>> edge[1001];

void foo(){
	f(i,1,n)t[i]=1e6,chk[i]=n;
	
	priority_queue<info> q;
	q.push({s,0,0});
	while(!q.empty()){
		info tmp=q.top();q.pop();
		
		if(chk[tmp.u]<=tmp.cnt)continue;
		
		chk[tmp.u]=tmp.cnt;
		if(tmp.u==d){
			t[tmp.cnt]=tmp.w;
			continue;
		}
				
		for(auto e:edge[tmp.u])if(chk[e.first]>tmp.cnt+1){
			q.push({e.first,tmp.w+e.second,tmp.cnt+1});
		}
	}
}

int sol(int val){
	int mn=3e8,nIdx=0;
	f(i,1,idx){
		int tmp=t[i]+val*i;
		if(mn>tmp){
			mn=tmp;
			nIdx=i;
		}
	}
	idx=nIdx;
	return mn;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m>>k>>s>>d;
	idx=n;
	while(m--){
		int a,b,w;cin>>a>>b>>w;
		edge[a].push_back({b,w});
		edge[b].push_back({a,w});
	}
	
	foo();
	int val=0;
	while(k--){
		cout<<sol(val)<<'\n';
		int tmp;cin>>tmp;
		val+=tmp;
	}
	cout<<sol(val)<<'\n';
	
	return 0;
}
