#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;
string a,b,c;
int s[201][201];

int foo(int i,int j){
	int k=i+j;
	if(k==c.length())return 1;
	if(s[i][j]!=-1)return 0;
	if(i<a.length()&&c[k]==a[i]&&foo(i+1,j))return 1;
	if(j<b.length()&&c[k]==b[j]&&foo(i,j+1))return 1;
	return s[i][j]=0;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;cin>>t;
	f(i,0,t){
		cin>>a>>b>>c;
		memset(s,-1,sizeof(s));
		cout<<"Data set "<<i+1<<": "<<(foo(0,0)?"yes":"no")<<'\n';
	}
		
	return 0;
}
