#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
#define fr(i,l,r) for(int i=l;i>=r;--i)
using namespace std;
int m,n,idx,tmp,s[1399],ans[700][700];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>m>>n;
	
	while(n--){
		idx=0;
		f(i,0,3){
			cin>>tmp;
			while(tmp--)s[idx++]+=i;
		}
	}
	
	idx=0;
	fr(i,m-1,0)ans[i][0]=s[idx++]+1;
	f(i,1,m)ans[0][i]=s[idx++]+1;
	
	
	ans[1][1]=max(ans[0][0],max(ans[0][1],ans[1][0]));
	f(i,2,m)ans[1][i]=max(ans[0][i],ans[1][i-1]);
	f(i,2,m)f(j,1,m)ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
	
	f(i,0,m){
		f(j,0,m)cout<<ans[i][j]<<' ';
		cout<<'\n';
	}
	return 0;
}
