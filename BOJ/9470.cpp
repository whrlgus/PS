#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

vector<int> v[1001];
int s[1001];

int sol(int i){
	int &ref=s[i];
	if(ref!=-1)return ref;
	ref=1;
	int cnt=0;
	for(int j:v[i]){
		int tmp=sol(j);
		if(ref==tmp)++cnt;
		if(ref<tmp)ref=tmp,cnt=1;
		ref=max(ref,sol(j));
	}
	return ref+=(cnt>1);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;cin>>t;
	while(t--){
		int k,m,p;cin>>k>>m>>p;
		memset(s,-1,sizeof(s));
		f(i,1,m)v[i].clear();
		while(p--){
			int a,b;cin>>a>>b;
			v[b].push_back(a);
		}
		int ans=0;
		f(i,1,m)ans=max(ans,sol(i));
		cout<<k<<' '<<ans<<'\n';
	}
	return 0;
}
