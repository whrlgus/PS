#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MAXN=2500;
char a[MAXN+1];
bool p[MAXN][MAXN];
int n,s[MAXN];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>a;
	n=strlen(a);
	
	f(i,1,n)f(j,i,n)p[j-i][j]=a[j-i]!=a[j]?true:p[j-i+1][j-1];
	f(i,1,n){
		if(!p[0][i])continue;
		s[i]=MAXN;
		f(j,0,i)if(!p[j+1][i])s[i]=min(s[i],s[j]+1);
	}
	cout<<s[n-1]+1;
	return 0;
}
