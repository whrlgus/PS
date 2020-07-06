#include<bits/stdc++.h>
using namespace std;

int sol(){
	int n;cin>>n;
	if(n==0)return 0;
	if(n==1)return 1;
	int a=0,b=1;
	while(--n){
		int tmp=a+b;
		a=b;
		b=tmp;
	}
	return b;
}

int main(){
	cout<<sol();
	return 0;
}
