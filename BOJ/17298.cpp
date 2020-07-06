#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
#define fr(i,l,r) for(int i=l;i>=r;--i)
using namespace std;

const int MAXN=1e6;
int n,a[MAXN+1],b[MAXN];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n)cin>>a[i];
	a[n]=-1;
	fr(i,n-1,0){
		int j=i+1;
		while(j<n&&a[i]>=a[j])j=b[j];
		b[i]=j;
	}
	f(i,0,n)cout<<a[b[i]]<<' ';
	return 0;
}
