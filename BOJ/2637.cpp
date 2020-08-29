#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int>> pre[101];
map<int,int> s[101];

void sol(int x){
	if(!s[x].empty())return;
	if(pre[x].size()==0){
		s[x][x]=1;
		return;
	}
	
	for(auto &a:pre[x]){
		sol(a.first);
		for(auto &b:s[a.first])s[x][b.first]+=(b.second*a.second);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	while(m--){
		int x,y,k;cin>>x>>y>>k;
		pre[x].push_back({y,k});
	}
	sol(n);
	for(auto &tmp:s[n])cout<<tmp.first<<' '<<tmp.second<<'\n';
	
	return 0;
}
