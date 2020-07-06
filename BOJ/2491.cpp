#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n,a,b,s[2]={1,1},ans=1;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>a;
	while(--n){
		cin>>b;
		s[0]=1+(a<=b?s[0]:0);
		s[1]=1+(a>=b?s[1]:0);
		ans=max(ans,max(s[0],s[1]));
		a=b;
	}
	cout<<ans;
	return 0;
}
