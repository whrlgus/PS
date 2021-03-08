#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int n,p[2][1001],s[1001][1001];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,1)f(j,1,n)cin>>p[i][j];
	
	f(i,1,n)f(j,1,n)s[i][j]=max(s[i][j-1],max(s[i-1][j],s[i-1][j-1]+(abs(p[0][i]-p[1][j])<=4)));
	
	cout<<s[n][n];
	
	return 0;
}
