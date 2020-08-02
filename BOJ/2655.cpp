#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n,a[101][3],s[101][2];
vector<int> ans;

int dfs(int i){
	int &ref=s[i][0];
	if(ref!=-1)return ref;
	ref=0;
	int k=-1;
	f(j,0,n)if(a[i][0]<a[j][0]&&a[i][2]<a[j][2]){
		int tmp=dfs(j);
		if(ref<tmp)ref=tmp,k=j;
	}
	s[i][1]=k;
	return ref+=a[i][1];
}

void sol(int i){
	ans.push_back(i+1);
	if(s[i][1]!=-1)sol(s[i][1]);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(s,-1,sizeof(s));
	cin>>n;
	f(i,0,n)cin>>a[i][0]>>a[i][1]>>a[i][2];
	
	dfs(n);
	sol(s[n][1]);
	cout<<ans.size()<<'\n';
	for(int i:ans)cout<<i<<'\n';
	return 0;
}
