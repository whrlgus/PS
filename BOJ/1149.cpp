#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int a[3],s[2][3],idx;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	f(i,0,n){
		idx^=1;
		cin>>a[0]>>a[1]>>a[2];
		s[idx][0]=min(s[idx^1][1],s[idx^1][2])+a[0];
		s[idx][1]=min(s[idx^1][0],s[idx^1][2])+a[1];
		s[idx][2]=min(s[idx^1][0],s[idx^1][1])+a[2];
	}
	cout<<min(s[idx][0],min(s[idx][1],s[idx][2]));
	return 0;
}
