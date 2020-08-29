#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string a;cin>>a;
	int i=a.length()%3;
	if(i)a=(i==1?"00":"0")+a;
	string ans;
	for(i=0;i<a.length();i+=3){
		int tmp=(a[i]-'0')*4+(a[i+1]-'0')*2+(a[i+2]-'0');
		ans.push_back('0'+tmp);
	}
	cout<<ans;
	
	return 0;
}
