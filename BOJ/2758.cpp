#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

long long s[11][2001];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f(i,1,2000)s[1][i]=i;
	f(i,2,10){
		int tmp=1<<(i-1);
		s[i][tmp]=1;
		f(j,tmp+1,2000)s[i][j]=s[i][j-1]+s[i-1][j>>1];
	}
	
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		cout<<s[n][m]<<'\n';
	}
	
	return 0;
}
