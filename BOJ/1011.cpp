#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

typedef long long ll;

int sol(ll n){
	ll tmp=0,ans=1;
	while(1){
		tmp+=((ans+1)>>1);
		if(tmp>=n)return ans;
		++ans;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;cin>>t;
	while(t--){
		ll x,y;cin>>x>>y;
		cout<<sol(y-x)<<'\n';
	}
	return 0;
}
