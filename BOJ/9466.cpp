#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int MXN=1e5+1;
int n,p[MXN],s[MXN];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		f(i,1,n)cin>>p[i];
		memset(s,0,sizeof(s));
		int ans=n,k=1;
		f(i,1,n)if(!s[i]){
			int j=i;
			while(!s[j]){
				s[j]=k++;
				j=p[j];
			}
			if(s[i]<=s[j])ans-=(k-s[j]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
