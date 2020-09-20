#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

typedef long long ll;
int n,m,a[10000];

int sol(){
	if(n<=m)return n;
	n-=m;
	ll l=1,r=6e10,tmp;
	while(l<r){
		ll mid=(l+r)/2;
		tmp=0;
		f(i,0,m)tmp+=mid/a[i];
		(tmp>=n)?r=mid:l=mid+1;
	}
	
	--r;
	tmp=n;
	f(i,0,m)tmp-=r/a[i];
	++r;
	f(i,0,m)if(r%a[i]==0&&(--tmp)==0)return i+1;
	
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	f(i,0,m)cin>>a[i];
	cout<<sol();
	
	return 0;
}
