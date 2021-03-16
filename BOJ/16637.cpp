#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n;
string str;

int calc(int i,int a,int b){
	char &c=str[i];
	
	if(c=='+')return a+b;
	else if(c=='-')return a-b;
	else return a*b;
}

int sol(int i,int j,int a){
	if(i==n||(j&&i>n-4))return INT_MIN;
	
	if(i==n-2)return calc(i,a,str[i+1]-'0');
	if(j&&i==n-4)return calc(i,a,calc(i+2,str[i+1]-'0',str[i+3]-'0'));
	
	if(j) return sol(i+4,0,calc(i,a,calc(i+2,str[i+1]-'0',str[i+3]-'0')));
	return max(sol(i,1,a),sol(i+2,0,calc(i,a,str[i+1]-'0')));
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>str;
	cout<<(n==1?str[0]-'0':sol(1,0,str[0]-'0'));
	return 0;
}
