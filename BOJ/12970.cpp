#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

string sol(){
	int n,k;cin>>n>>k;
	
	string s(n,'B');
	if(k==0){
		s[n-1]='A';
		return s;
	}
	
	f(i,0,n){
		s[i]='A';
		int tmp=(i+1)*(n-i-1);
		if(tmp<k)continue;
		swap(s[i], s[i+tmp-k]);
		return s;
	}
	return "-1";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout<<sol();
	return 0;
}
