#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;
typedef long long ll;

int N,M,K,offset=1;
ll T[1024*1024*2];

void update(int x,ll val){
	x+=offset;
	T[x]=val;
	while(x>>=1){
		int tmp=x<<1;
		T[x]=T[tmp]+T[tmp+1];
	}
}

ll query(int l,int r){
	l+=offset;
	r+=offset;
	ll sum=0;
	while(l!=r){
		if(l&1)sum+=T[l-1];
		if(!(r&1))sum+=T[r+1];
		l>>=1;
		r>>=1;
	}
	return T[l]-sum;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int i=100,n=200;
	for(;i<=n;i-=i&-i)cout<<i;
	cin>>N>>M>>K;
	while(offset<N)offset<<=1;
	--offset;
	f(i,1,N){
		ll val;cin>>val;
		update(i,val);
	}
	M+=K;
	int a,b;
	ll c;
	while(M--){
		cin>>a>>b>>c;
		if(a==1)update(b,c);
		else cout<<query(b,c)<<'\n';
	}
	return 0;
}
