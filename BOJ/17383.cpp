#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n,t[100000];

bool isValid(int m){
	int cnt = 0;
	f(i,0,n)cnt+=1-(t[i]-1)/m;
	return cnt>0;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n)cin>>t[i];
	sort(t,t+n);
	
	int l=1,r=t[n-1];
	while(l<=r){
		int m=(l+r)/2;
		isValid(m)?r=m-1:l=m+1;
	}
	cout<<r+1;
	
	return 0;
}
