#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	long long ans=n;
	f(i,1,n){
		int num;cin>>num;
		ans+=num-i;
	}
	cout<<ans;
	return 0;
}
