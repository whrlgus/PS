#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;
typedef long long ll;
const int MAXN=3e5;
int n;
ll d[MAXN],y[MAXN];

ll count(ll start){
	int m=n/2;
	
	ll h=start,cnt=abs(h-d[m])+abs(h-y[m]),i=m,j=m;
	while(m--){
		h+=1;i-=1;j+=1;
		cnt+=abs(h-d[i])+abs(h-y[i])+abs(h-d[j])+abs(h-y[j]);
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n)cin>>d[i];
	f(i,0,n)cin>>y[i];
	
	ll l=0,r=1e12;
	while(l<r){
		ll m=(l+r)/2;
		if(count(m)<count(m+1))r=m;
		else l=m+1;
	}
	cout<<count(r);
	return 0;
}
