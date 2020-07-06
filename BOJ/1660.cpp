#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,val=4,a=3,b=3,s[300001];
	cin>>n;
	f(i,0,n)s[i]=i;
	while (val<=n){
		f(i,val,n){
			s[i]=min(s[i],s[i-val]+1);
		}
		a+=b;
		b+=1;
		val+=a;
	}
	cout<<s[n];
	
	return 0;
}
