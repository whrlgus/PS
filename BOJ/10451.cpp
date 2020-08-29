#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n,a[1001],cnt=0,tmp;
		bool vis[1001]{};
		cin>>n;
		f(i,1,n)cin>>a[i];
		f(i,1,n)if(!vis[i]){
			++cnt;
			tmp=a[i];
			while(tmp!=i){
				vis[tmp]=true;
				tmp=a[tmp];
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
