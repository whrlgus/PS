#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	int ans=1,a=1,b=6;
	while(a<n){
		a+=b;
		b+=6;
		++ans;
	}
	cout<<ans;
	return 0;
}
