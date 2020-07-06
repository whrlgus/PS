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


string s[101][101]={{"1"},{"1","1"}};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	f(i,1,100){
		s[i+1][0]=s[i+1][i+1]="1";
		f(j,0,i)s[i+1][j+1]=s[i][j]+s[i][j+1];
	}
	
	int n,m;cin>>n>>m;
	reverse(s[n][m].begin(),s[n][m].end());
	cout<<s[n][m];
	
	return 0;
}
