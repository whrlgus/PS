#include<bits/stdc++.h>
using namespace std;

int sol(){
	int n;cin>>n;
	int i=n/5+1;
	while(--i){
		if((n-5*i)&1)continue;
		return i+((n-5*i)>>1);
	}
	return n&1?-1:n>>1;
}

int main(){
	cout<<sol();
	return 0;
}
