#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

vector<int> v[1001];
int cnt[1001];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;cin>>n>>m;
	while(m--){
		int k,a,b;cin>>k>>a;
		while(--k){
			cin>>b;
			v[a].push_back(b);
			a=b;
			++cnt[b];
		}
	}
	
	queue<int> q;
	f(i,1,n)if(!cnt[i])q.push(i);
	vector<int> ans;
	while(!q.empty()){
		int i=q.front();q.pop();
		ans.push_back(i);
		for(int j:v[i])if(!(--cnt[j]))q.push(j);
	}
	if(ans.size()!=n)cout<<0;
	else for(int i:ans)cout<<i<<'\n';
	return 0;
}
