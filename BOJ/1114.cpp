#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int L,K,C,a[10002],ans;

bool foo(int m){
	int l=K-1,r=K+1,cnt=C;
	while(l>=0){
		if(a[r]-a[l]>m){
			if(cnt--==0||a[r]-a[l+1]>m)return false;
			r=l+1;
		}
		--l;
	}
	ans=cnt?a[1]:a[r];
	return a[r]-a[l+1]<=m;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>L>>K>>C;
	f(i,0,K)cin>>a[i];
	a[K]=0;
	a[K+1]=L;
	sort(a,a+K+2);
	
	int l=0,r=1e9;
	while(l<r){
		int m=(l+r)>>1;
		foo(m)?r=m:l=m+1;
	}
	cout<<r<<' '<<ans;
	return 0;
}
