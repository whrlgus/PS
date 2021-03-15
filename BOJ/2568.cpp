#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int N=5e5+1;
int s[N],t[N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<pair<int,int>> v;
	int n;cin>>n;
	while(n--){
		int a,b;cin>>a>>b;
		v.push_back({a,b});
		t[b]=a;
	}
	
	sort(v.begin(),v.end());
	vector<int> p;
	for(auto &ele:v){
		int idx=lower_bound(p.begin(),p.end(),ele.second)-p.begin();
		if(idx==p.size())p.push_back(ele.second);
		else p[idx]=ele.second;
		s[ele.second]=idx+1;
	}
	
	int cnt=p.size();
	vector<int> ans;
	for(int i=N;i>=0;--i){
		if(cnt==s[i])--cnt;
		else if(s[i]>0)ans.push_back(t[i]);
	}
	
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<'\n';
	for(int num:ans)cout<<num<<'\n';
	
	return 0;
}
