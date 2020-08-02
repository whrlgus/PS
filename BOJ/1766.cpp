#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int MAXN=32001;
vector<int> v[MAXN];
int cnt[MAXN];


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;cin>>n>>m;
	while(m--){
		int a,b;cin>>a>>b;
		v[a].push_back(b);
		++cnt[b];
	}
	
	priority_queue<int> q;
	f(i,1,n)if(!cnt[i])q.push(-i);
	while(!q.empty()){
		int i=-q.top();q.pop();
		cout<<i<<' ';
		for(int j:v[i])if(!(--cnt[j]))q.push(-j);
	}
	
	return 0;
}
