#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MAXN=1e4;
int a[MAXN],b[MAXN];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,k;cin>>n>>k;
	f(i,0,n)cin>>a[i];
	sort(a,a+n);
	f(i,1,n)b[i]=a[i]-a[i-1];
	sort(b+1,b+n);
	int ans=a[n-1]-a[0];
	k=min(k,n);
	f(i,1,k)ans-=b[n-i];
	cout<<ans;
	return 0;
}

