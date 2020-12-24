#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int t,n,a[1001];

int sol(){
	int ret=a[0],tmp=0;
	f(i,0,n){
		tmp+=a[i];
		ret=max(ret,tmp);
		if(tmp<0)tmp=0;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		f(i,0,n)cin>>a[i];
		cout<<sol()<<'\n';
	}
	return 0;
}
