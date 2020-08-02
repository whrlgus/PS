#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int MAXN=1001;
vector<int> v[MAXN];
int s[MAXN];

int sol(int i){
	int &ref=s[i];
	if(ref!=-1)return ref;
	ref=0;
	for(int j:v[i])ref=max(ref,sol(j));
	return ref+=1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;cin>>n>>m;
	while(m--){
		int a,b;cin>>a>>b;
		v[b].push_back(a);
	}
	memset(s,-1,sizeof(s));
	f(i,1,n)cout<<sol(i)<<' ';
	return 0;
}
