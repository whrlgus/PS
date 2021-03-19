#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

typedef long long ll;

ll sol(ll x){
	ll cnt=__builtin_popcountll(x),ret=cnt;
	for(int i=0;1LL<<i<=x;++i){
		if(x>>i&1){
			--cnt;
			ret+=cnt*(x-(1LL<<i)^x)+(1LL<<(i-1))*i;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll a,b;cin>>a>>b;
	cout<<sol(b)-sol(a-1);
	return 0;
}
