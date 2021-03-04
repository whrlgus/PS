#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

string str;
int b;

void sol(int n){
	if(!n)return;
	int tmp=n%b;
	sol(n/b);
	cout<<str[tmp];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f(i,0,10)str.push_back('0'+i);
	f(i,0,26)str.push_back('A'+i);
	int n;cin>>n>>b;
	sol(n);
	return 0;
}
