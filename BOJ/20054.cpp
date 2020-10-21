#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

typedef long long ll;
const int MOD=1e9+7;
int n,k,s[3501][13];

ll sol(int cnt,int h){
	int &ref=s[cnt][h--];
	if(ref!=-1)return ref;
	ll tmp=0;
	int l=0,r=cnt-1;
	while(l<r)tmp=(tmp+sol(l++,h)*sol(r--,h))%MOD;
	tmp=(tmp<<1)%MOD;
	if(l==r)tmp=(tmp+sol(l,h)*s[l][h])%MOD;
	return ref=tmp;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	memset(s,-1,sizeof(s));
	f(i,1,k)s[0][i]=s[1][i]=1;
	f(i,2,n)s[i][1]=0;
	cout<<sol(n,k);
	
	return 0;
}
