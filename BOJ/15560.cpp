#include<bits/stdc++.h>
using namespace std;
int n,q,u,v,k[1001];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>q>>u>>v;
	for(int i=1;i<=n;++i){
		cin>>k[i];
		k[i]=u*k[i]+v;
	}
	
	while(q--){
		int c,a,b;cin>>c>>a>>b;
		if(c)k[a]=u*b+v;
		else {
			int sum=0,ans=k[a]-v;
			for(int i=a;i<=b;++i){
				sum+=k[i];
				ans=max(ans,sum-v);
				if(sum<0)sum=0;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}

