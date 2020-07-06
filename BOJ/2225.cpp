#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int MOD=1e9;
int s[201][201];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,k;cin>>n>>k;
	f(i,0,n)s[1][i]=1;
	f(i,2,k)f(j,0,n)f(k,0,j)s[i][j]=(s[i][j]+s[i-1][k])%MOD;
	cout<<s[k][n];
	return 0;
}
