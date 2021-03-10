#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	long long ans=0;
	int mx,mn,a;cin>>a;
	mx=mn=a;
	while(--n){
		cin>>a;
		if(mn>a)mn=a;
		else{
			ans+=(a-mn);
			mn=a;
			mx=max(mx,mn);
			if(mx<=a){
				ans+=(a-mx);
				mx=a;
			}
		}
	}
	cout<<ans+(mx-mn);
	return 0;
}
