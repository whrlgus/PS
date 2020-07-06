#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
#define N 1001
using namespace std;

int n,p,s[N];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	cin>>p;
	f(i,1,n)s[i]=s[i-1]+p;
	f(i,2,n){
		cin>>p;
		f(j,i,n)s[j]=min(s[j],s[j-i]+p);
	}
	cout<<s[n];
	
	return 0;
}
