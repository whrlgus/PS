#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int t,w,a[1001],s[31][1001],ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>t>>w;
	
	f(i,1,t)cin>>a[i],s[0][i]=s[0][i-1]+(a[i]&1);
	f(i,1,w)f(j,1,t)s[i][j]=max(s[i-1][j-1],s[i][j-1])+((a[j]+i)&1);
	f(i,0,w)ans=max(ans,s[i][t]);
	cout<<ans;
	return 0;
}
