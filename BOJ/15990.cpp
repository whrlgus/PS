#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MAXN=1e5+1;
const int MOD=1e9+9;
unsigned int s[MAXN][4];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	s[1][1]=s[2][2]=s[3][1]=s[3][2]=s[3][3]=1;
	f(i,4,MAXN){
		s[i][1]=(s[i-1][2]+s[i-1][3])%MOD;
		s[i][2]=(s[i-2][1]+s[i-2][3])%MOD;
		s[i][3]=(s[i-3][1]+s[i-3][2])%MOD;
	}
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		cout<<(s[n][1]+s[n][2]+s[n][3])%MOD<<'\n';
	}
	return 0;
}
