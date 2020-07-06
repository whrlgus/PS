#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int A[1001]={1,1};

bool isValid(int i){
	int k=0;
	while(i-2*(++k)>=0)
		if(A[i]-A[i-k]==A[i-k]-A[i-2*k])
			return false;
	return true;
}

int main(){
	int n;cin>>n;
	f(i,2,n){
		A[i]=0;
		while(++A[i])if(isValid(i))break;
	}
	cout<<A[n];
	return 0;
}
