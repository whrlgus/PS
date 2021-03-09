#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

typedef pair<int,int> pii;
int N,M,t[1<<18][2];

void build(){
	for(int i=N-1;i>0;--i){
		t[i][0]=min(t[i<<1][0],t[i<<1|1][0]);
		t[i][1]=max(t[i<<1][1],t[i<<1|1][1]);
	}
}

pii query(int l,int r){
	pii ret={1e9,0};
	for(l+=N,r+=N;l<r;l>>=1,r>>=1){
		if(l&1)ret={min(ret.first,t[l][0]),max(ret.second,t[l][1])},++l;
		if(r&1)--r,ret={min(ret.first,t[r][0]),max(ret.second,t[r][1])};
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N>>M;
	f(i,0,N){
		int num;cin>>num;
		t[i+N][0]=t[i+N][1]=num;
	}
	build();
	while(M--){
		int a,b;cin>>a>>b;
		pii ans=query(a-1,b);
		cout<<ans.first<<' '<<ans.second<<'\n';
	}
	return 0;
}
