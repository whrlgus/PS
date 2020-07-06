#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int T,N,a[21],M,s[10001]={1};
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		cin>>N;
		f(i,1,N)cin>>a[i];
		cin>>M;
		memset(s+1, 0, 4*M);
		f(i,1,N)f(j,a[i],M)s[j]+=s[j-a[i]];
		cout<<s[M]<<'\n';
	}
	return 0;
}
