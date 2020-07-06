#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
#define fr(i,l,r) for(int i=l;i>=r;--i)
#define N 1001
using namespace std;

int n,mx,mn,a[N],s[N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n)cin>>a[i];
	f(i,0,n){
		mx=mn=a[i];
		fr(j,i,0){
			mx=max(mx,a[j]);
			mn=min(mn,a[j]);
			s[i+1]=max(s[i+1],s[j]+mx-mn);
		}
	}
	cout<<s[n];
	return 0;
}
