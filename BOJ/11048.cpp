#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int s[2][1001],idx;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;cin>>n>>m;
	f(i,1,n){
		idx^=1;
		f(j,1,m){
			int tmp;cin>>tmp;
			s[idx][j]=max(s[idx][j-1],max(s[idx^1][j],s[idx^1][j-1]))+tmp;
		}
	}
	cout<<s[idx][m];
	
	return 0;
}
