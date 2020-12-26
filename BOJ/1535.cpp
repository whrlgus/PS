#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
#define fr(i,l,r) for(int i=l;i>=r;--i)
using namespace std;

int n,l[20],j[20],s[100];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n)cin>>l[i];
	f(i,0,n)cin>>j[i];
	
	f(i,0,n)fr(k,99-l[i],0){
		int tmp=k+l[i];
		s[tmp]=max(s[tmp],s[k]+j[i]);
	}
	
	int ans=0;
	f(i,0,100)ans=max(ans,s[i]);
	cout<<ans;
	return 0;
}
