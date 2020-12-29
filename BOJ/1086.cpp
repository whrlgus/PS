#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

typedef long long ll;
int N,K,a[15],b[15];
ll s[1<<15][100];
string nums[15];

int transform(string num){
	int ret=0;
	for(char c:num)ret=(c-'0'+ret*10)%K;
	return ret;
}

ll sol(int i,int j,int k){
	ll &ref=s[i][j];
	if(ref!=-1)return ref;
	if(i==(1<<N)-1)return ref=(j==0);
	
	ref=0;
	f(l,0,N)if(!((i>>l)&1))ref+=sol(i|(1<<l),(j+a[l]*k)%K,(k*b[l])%K);
	return ref;
}

ll fac(int x){
	return x==1?1:fac(x-1)*x;
}

ll gcd(ll x,ll y){
	return y==0?x:gcd(y,x%y);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N;
	f(i,0,N)cin>>nums[i];
	cin>>K;
	
	f(i,0,N){
		a[i]=transform(nums[i]);
		b[i]=transform('1'+string(nums[i].length(),'0'));
	}
	
	memset(s,-1,sizeof(s));
	ll p=sol(0,0,1),q=fac(N),r=gcd(p,q);
	cout<<p/r<<'/'<<q/r;
	return 0;
}
