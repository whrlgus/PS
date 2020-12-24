#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
#define fr(i,l,r) for(int i=l;i>=r;--i)
using namespace std;

string s[251]={"1","1","3"};

void calc(int n){
	string &ref=s[n];
	if(ref!="")return;
	
	--n;
	calc(n);
	
	int carry=n&1?1:-1;
	f(i,0,s[n].length()){
		int tmp=s[n][i]-'0';
		tmp<<=1;
		tmp+=carry;
		ref.push_back(tmp%10+'0');
		carry=tmp/10;
	}
	if(carry)ref.push_back(carry+'0');
}

void sol(int n){
	calc(n);
	fr(i,s[n].length()-1,0)cout<<s[n][i];
	cout<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	while(cin>>n)sol(n);
	return 0;
}
