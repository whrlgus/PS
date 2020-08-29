#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n,m,l,r,sum;
vector<pair<int,int>> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	while(n--){
		int a,b;cin>>a>>b;
		if(a>b)v.push_back({b,a});
	}
	
	sort(v.begin(),v.end());
		
	for(auto &tmp:v){
		if(r<tmp.first){
			sum+=(r-l)*2;
			l=tmp.first;
		}
		r=max(r,tmp.second);
	}
	cout<<((long long)m+sum+(r-l)*2);
	return 0;
}
