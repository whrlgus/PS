#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
#define fr(i,l,r) for(int i=l;i>=r;--i)
using namespace std;

string removeZero(string num){
	int i=0;
	while(i<num.length()&&num[i]=='0')++i;
	if(i==num.length())--i;
	return num.substr(i);
}

string padZero(string num,int len){
	if(num.length()==len)return num;
	return string(len-num.length(),'0')+num;
}

string add(string a, string b){
	string sum(a.length(),'0');
	int carry=0;
	fr(i,a.length()-1,0){
		int tmp=carry+a[i]+b[i]-96;
		carry=tmp/2;
		sum[i]=tmp%2+48;
	}
	return (carry?"1":"")+sum;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string a,b;cin>>a>>b;
	a=removeZero(a),b=removeZero(b);
	int len=max(a.length(),b.length());
	cout<<add(padZero(a,len),padZero(b,len));
	
	return 0;
}
