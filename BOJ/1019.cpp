#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

typedef long long ll;

ll pow10(int x){
	ll ret=1;
	while(x--)ret*=10;
	return ret;
}

void foo(ll (&a)[10],int i){
	if(!i)return;
	ll val=pow10(i-1)*i;
	f(i,0,10)a[i]+=val;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	
	ll a[10]{},tmp=n;
	while(tmp){
		++a[tmp%10];
		tmp/=10;
	}
	
	ll b[10];
	f(i,0,10)b[i]=a[i];
	int i=0;
	while(n){
		tmp=n%10;
		--a[tmp];
		ll p=pow10(i);
		f(j,0,10)b[j]+=a[j]*tmp*p;
		while(tmp){
			foo(b,i);
			b[--tmp]+=p;
		}
		++i;
		n/=10;
	}
	tmp=pow10(i-1);
	while(tmp){
		b[0]-=tmp;
		tmp/=10;
	}
	
	f(i,0,10)cout<<b[i]<<' ';
	
	return 0;
}
