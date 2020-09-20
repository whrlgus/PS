#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;
typedef long long ll;

const int MX=1e5+2;
int n,h[MX];

ll sol(int a,int b){
	if(a>b)return 0;
	
	int m=(a+b)/2,l=m-1,r=m+1,val=h[m],tmpa=h[a-1],tmpb=h[b+1];;
	ll ans=h[m];
	h[a-1]=h[b+1]=0;
	
	while(h[l]||h[r]){
		val=min(val,h[l]>h[r]?h[l--]:h[r++]);
		ans=max(ans,(ll)(r-l-1)*val);
	}
	h[a-1]=tmpa,h[b+1]=tmpb;
	return max(ans,max(sol(a,m-1),sol(m+1,b)));
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,1,n)cin>>h[i];
	cout<<sol(1,n);
	return 0;
}
