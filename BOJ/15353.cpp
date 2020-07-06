#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

string operator+(string a, string b){
	string ret;
	if(a.length()<b.length())a.swap(b);
	int carry=0;
	f(i,0,b.length()){
		int tmp=a[i]-'0'+b[i]-'0'+carry;
		carry=tmp/10;
		tmp%=10;
		ret.push_back(tmp+'0');
	}
	f(i,b.length(),a.length()){
		int tmp=a[i]-'0'+carry;
		carry=tmp/10;
		tmp%=10;
		ret.push_back(tmp+'0');
	}
	if(carry)ret.push_back(carry+'0');
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string a,b;cin>>a>>b;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	string c=a+b;
	reverse(c.begin(),c.end());
	cout<<c;
	return 0;
}
