#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MOD=1e6;
int s[5001]={1};

int sol(){
	string str;cin>>str;
	if(str[0]=='0')return 0;
	s[1]=1;
	f(i,1,str.length()){
		if(str[i]=='0'){
			if(str[i-1]!='1'&&str[i-1]!='2')return 0;
			s[i+1]=s[i-1];
		}else{
			s[i+1]=s[i];
			if(str[i-1]=='1'||(str[i-1]=='2'&&str[i]<='6'))s[i+1]=(s[i+1]+s[i-1])%MOD;
		}
	}
	return s[str.length()];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout<<sol();
	return 0;
}
