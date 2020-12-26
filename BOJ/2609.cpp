#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int gcd(int a, int b){
	return b?gcd(b,a%b):a;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a,b;cin>>a>>b;
	int tmp=gcd(a,b);
	cout<<tmp<<'\n';
	cout<<tmp*a/tmp*b/tmp;
	return 0;
}
