#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;
int T,k,p,n,s[2][10001];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>T>>k;
	s[0][0]=1;
	while(k--){
		cin>>p>>n;
		f(i,0,T)if(s[0][i])f(j,1,n){
			int tmp=i+j*p;
			if(tmp>T)break;
			s[1][tmp]+=s[0][i];
		}
		f(i,0,T)s[0][i]+=s[1][i],s[1][i]=0;
	}
	cout<<s[0][T];
	return 0;
}
