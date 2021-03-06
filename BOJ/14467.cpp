#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,p[11],cnt[11]{},chk[11]{},ans=0;
	cin>>n;
	while(n--){
		int i,j;cin>>i>>j;
		if(!chk[i])chk[i]=1,p[i]=j;
		else if(p[i]!=j)++ans,p[i]=j;
	}
	cout<<ans;
	return 0;
}
