#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int p;cin>>p;
	while(p--){
		int n,m;cin>>n>>m;
		int a=1,b=2,ans=1;
		while(a!=1||b!=1){
			int tmp=b;
			b=(a+b)%m;
			a=tmp;
			++ans;
		}
		
		cout<<n<<' '<<ans<<'\n';
	}
	return 0;
}
