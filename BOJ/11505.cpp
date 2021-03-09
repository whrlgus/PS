#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

typedef long long ll;
const int MOD=1e9+7;
int N,M,K,t[1<<21];

void build(){
	for(int i=N-1;i>0;--i)t[i]=((ll)t[i<<1]*t[i<<1|1])%MOD;
}

void update(int i,int j){
	for(t[i+=N]=j;i>1;i>>=1)t[i>>1]=((ll)t[i]*t[i^1])%MOD;
}

int query(int l,int r){
	int ret=1;
	for(l+=N,r+=N;l<r;l>>=1,r>>=1){
		if(l&1)ret=((ll)ret*t[l++])%MOD;
		if(r&1)ret=((ll)ret*t[--r])%MOD;
	}
	return ret;
}
		
		
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N>>M>>K;
	f(i,0,N)cin>>t[i+N];
	build();
	M+=K;
	while(M--){
		int a,b,c;cin>>a>>b>>c;
		if(a==1)update(b-1,c);
		else cout<<query(b-1,c)<<'\n';
	}
	return 0;
}
