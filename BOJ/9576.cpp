#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		int a[1000][2];
		for(int i=0;i<m;++i)cin>>a[i][0]>>a[i][1];
			
		int ans=0,INF=1001;
		for(int i=1;i<=n;++i){
			int idx=-1,tmp=INF;
			for(int j=0;j<m;++j)if(i==a[j][0]){
				if(a[j][0]<a[j][1])++a[j][0];
				if(a[j][1]<tmp)idx=j,tmp=a[j][1];
			}
			if(idx!=-1){
				++ans;
				a[idx][0]=INF;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
