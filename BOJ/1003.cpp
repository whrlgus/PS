#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int s[41][2]={{1,0},{0,1}};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	f(i,2,40){
		s[i][0]=s[i-1][0]+s[i-2][0];
		s[i][1]=s[i-1][1]+s[i-2][1];
	}
	
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		cout<<s[n][0]<<' '<<s[n][1]<<'\n';
	}
	return 0;
}
