#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MAXN=5000;
int a[MAXN],s[MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	f(i,0,n)cin>>a[i];
	
	f(i,1,n)f(j,i,n)s[j-i][j]=(a[j-i]==a[j]?s[j-i+1][j-1]:min(s[j-i][j-1],s[j-i+1][j])+1);
	cout<<s[0][n-1];
	
	return 0;
}
