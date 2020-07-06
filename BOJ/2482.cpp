#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int MOD=1e9+3;
int n,k,s[1001][2][501],t[1001][2][501];

int main(){
	cin>>n>>k;
	if((n+1)/2<k){
		cout<<0;
		return 0;
	}
	s[2][0][0]=s[2][1][1]=t[2][0][1]=1;
	f(i,3,n){
		int tmp=n/2+1;
		s[i][0][0]=s[i-1][0][0];
		t[i][0][0]=t[i-1][0][0];
		f(j,1,tmp){
			s[i][0][j]=(s[i-1][0][j]+s[i-1][1][j])%MOD;
			s[i][1][j]=s[i-1][0][j-1];
			t[i][0][j]=(t[i-1][0][j]+t[i-1][1][j])%MOD;
			t[i][1][j]=t[i-1][0][j-1];
		}
	}
	cout<<((long long)s[n][0][k]+s[n][1][k]+t[n][0][k])%MOD;
	return 0;
}
