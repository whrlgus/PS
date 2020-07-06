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

int n;
string s[10001]={"0","1"};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,1,n)s[i+1]=s[i]+s[i-1];
	reverse(s[n].begin(),s[n].end());
	cout<<s[n];
	return 0;
}
