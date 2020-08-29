#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int n,m,p[10001][2],sum[2];

int sol(int j){
	int l=0,r=m,prev=sum[j],curr,mn=prev;
	f(i,1,n){
		l+=p[i-1][j];
		curr=prev-r+l;
		if(prev<curr)break;
		r-=p[i][j];
		mn=min(mn,curr);
		prev=curr;
	}
	return mn;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	f(i,1,m){
		int a,b;cin>>a>>b;
		sum[0]+=a;
		sum[1]+=b;
		++p[a][0];
		++p[b][1];
	}
	cout<<sol(0)+sol(1);
	return 0;
}
