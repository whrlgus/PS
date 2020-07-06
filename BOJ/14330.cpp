#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int sol(){
	char a[6],b[7];
	cin>>a;
	int len=-1;
	while(a[++len])b[len+1]=a[len];
	b[0]=a[0];
	b[len+1]=a[len-1];
	
	int ans=1;
	f(i,1,len)ans*=(b[i-1]==b[i]?b[i]==b[i+1]?1:2:b[i]==b[i+1]||b[i-1]==b[i+1]?2:3);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;cin>>T;
	f(i,1,T)cout<<"Case #"<<i<<": "<<sol()<<'\n';
	return 0;
}
