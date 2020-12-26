#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n,s[2][3];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t=1;
	while(cin>>n&&n){
		f(i,0,3)cin>>s[0][i];
		s[0][0]=1e9;
		s[0][2]+=s[0][1];
		int k=0;
		while(--n){
			k^=1;
			f(i,0,3)cin>>s[k][i];
			s[k][0]+=min(s[k^1][0],s[k^1][1]);
			s[k][1]+=min(s[k][0],min(s[k^1][0],min(s[k^1][1],s[k^1][2])));
			s[k][2]+=min(s[k][1],min(s[k^1][1],s[k^1][2]));
		}
		cout<<t++<<". "<<s[k][1]<<'\n';
	}
	return 0;
}
