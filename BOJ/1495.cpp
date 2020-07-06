#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;
int N,S,M,V[101],ans=-1;
bool dp[101][1001];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N>>S>>M;
	f(i,1,N)cin>>V[i];
	dp[0][S]=true;
	f(i,1,N)f(j,0,1000)if(dp[i-1][j]){
		if(j-V[i]>=0)dp[i][j-V[i]]=true;
		if(j+V[i]<=M)dp[i][j+V[i]]=true;
	}
	
	f(i,0,M)if(dp[N][i])ans=max(ans,i);
	cout<<ans;
	return 0;
}
