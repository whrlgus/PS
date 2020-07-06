#include<bits/stdc++.h>
using namespace std;

int s[31]={1};

int main(){
	int n;cin>>n;
	for(int i=2;i<=n;i+=2){
		s[i]=s[i-2]*3;
		for(int j=4;j<=i;j+=2)s[i]+=s[i-j]*2;
	}
	cout<<s[n];
	return 0;
}
