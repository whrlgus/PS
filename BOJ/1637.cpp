#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

typedef long long ll;

int n,p[20000][3];

ll sum(int x){
	ll ret=0;
	f(i,0,n)if(p[i][0]<=x){
		int tmp=min(p[i][1],x),cnt=(tmp-p[i][0])/p[i][2];
		ret+=cnt+1;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n)cin>>p[i][0]>>p[i][1]>>p[i][2];
	
	ll l=1,r=2147483648;
	while(l<r){
		ll m=(l+r)>>1;
		if(sum(m)&1)r=m;
		else l=m+1;
	}
	if(l==2147483648)cout<<"NOTHING";
	else cout<<l<<' '<<sum(l)-sum(l-1);
	return 0;
}
