#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int s[101][2][101];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	s[1][0][0]=s[1][1][0]=1;
	f(i,2,101){
		s[i][0][0]=s[i-1][0][0]+s[i-1][1][0];
		s[i][1][0]=s[i-1][0][0];
		f(j,1,i){
			s[i][0][j]=s[i-1][0][j]+s[i-1][1][j];
			s[i][1][j]=s[i-1][0][j]+s[i-1][1][j-1];
		}
	}
	
	int t;cin>>t;
	while(t--){
		int n,k;cin>>n>>k;
		cout<<s[n][0][k]+s[n][1][k]<<'\n';
	}
	return 0;
}
