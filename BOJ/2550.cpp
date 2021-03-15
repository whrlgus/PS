#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
#define fr(i,l,r) for(int i=l;i>=r;--i)
using namespace std;

const int N=1e4+1;
int n,a[N],b[N],c[N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n){
		int num;cin>>num;
		a[num]=i;
	}
	
	vector<pair<int,int>> v;
	f(i,0,n){
		cin>>b[i];
		pair<int,int> tmp={a[b[i]],b[i]};
		int idx=lower_bound(v.begin(),v.end(),tmp)-v.begin();
		if(v.size()==idx)v.push_back(tmp);
		else v[idx]=tmp;
		c[b[i]]=idx+1;
	}
	
	vector<int> ans;
	int tmp=v.size();
	fr(i,n-1,0)if(c[b[i]]==tmp)ans.push_back(b[i]),--tmp;
	
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<'\n';
	for(int num:ans)cout<<num<<' ';
	
	return 0;
}
