#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

typedef long long ll;
const int MOD=1e9+7;

int pow(int a, int b){
	if(b<1)return 1;
	if(b&1)return ((ll)a*pow(a,b-1))%MOD;
	ll tmp=pow(a,b/2);
	return (tmp*tmp)%MOD;
}

int gcd(int a, int b){
	return b==0?a:gcd(b,a%b);
}

int exp(int n,int s){
	if(!(s%n)) return s/n;
	int g=gcd(n,s);
	n/=g;
	s/=g;
	return ((ll)s*pow(n,MOD-2))%MOD;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m;cin>>m;
	int ans=0;
	while(m--){
		int n,s;cin>>n>>s;
		ans=(ans+exp(n,s))%MOD;
	}
	cout<<ans;
	return 0;
}
