#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

typedef long long ll;
const int MXN=1e5;
int n,t[MXN];

ll sol(int s, int e){
	if(s==e)return t[s];
	
	int m=(s+e)>>1,l=m,r=m+1,h=min(t[l--],t[r++]);
	ll ret=h<<1;
	while(s<=l||r<=e){
		if(l<s) h=min(h,t[r++]);
		else if(e<r) h=min(h,t[l--]);
		else h=min(h,t[l]>t[r]?t[l--]:t[r++]);
		ret=max(ret,(ll)h*(r-l-1));
	}
	
	return max(ret,max(sol(s,m),sol(m+1,e)));
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n)cin>>t[i];
	cout<<sol(0,n-1);
	
	return 0;
}
