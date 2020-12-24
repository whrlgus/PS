#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MAXN=1e6,MOD=1e9;
int s[2*MAXN+1];

int sol(int n){
	if(s[n]!=-1)return s[n];
	if(n<MAXN)s[n]=sol(n+2)-sol(n+1);
	else s[n]=sol(n-1)+sol(n-2);
	return s[n]%=MOD;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(s,-1,sizeof(s));
	s[MAXN]=0;
	s[MAXN+1]=1;
	
	int n;
	cin>>n;
	int ans=sol(MAXN+n);
	cout<<(ans>0?1:ans==0?0:-1)<<'\n';
	cout<<abs(ans);
	
	return 0;
}
