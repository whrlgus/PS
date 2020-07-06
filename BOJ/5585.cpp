#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int sol(int n){
	int ret=0,i=500,j=1;
	while(i){
		ret+=n/i;
		n%=i;
		i/=(j?5:2);
		j^=1;
	}
	return ret;
}

int main(){
	int n;cin>>n;
	cout<<sol(1000-n);
	return 0;
}
