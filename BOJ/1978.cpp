#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

bool isPrime(int num){
	if(num==1)return false;
	f(i,2,num-1)if(num%i==0)return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	int cnt=0;
	while(n--){
		int num;cin>>num;
		if(isPrime(num))++cnt;
	}
	cout<<cnt;
	return 0;
}
