#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	double ans,prev;cin>>prev;
	ans=prev;
	while(--n){
		double curr;cin>>curr;
		prev=max(curr,curr*prev);
		ans=max(ans,prev);
	}
	cout<<setprecision(3)<<fixed<<ans;
	return 0;
}
