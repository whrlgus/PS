#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

pair<int,int> p[500];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	f(i,0,n)cin>>p[i].first>>p[i].second;
	sort(p,p+n);
	
	vector<int> v;
	f(i,0,n){
		int tmp=upper_bound(v.begin(), v.end(), p[i].second)-v.begin();
		if(tmp==v.size())v.push_back(p[i].second);
		else v[tmp]=p[i].second;
	}
	cout<<n-v.size();
	return 0;
}
