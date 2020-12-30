#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n,s[1<<15][10][15];
char p[15][16];

int sol(int i,int j,int k){
	int &ref=s[i][j][k];
	if(ref!=-1)return ref;
	ref=0;
	f(l,1,n)if(!((i>>l)&1)&&p[k][l]>=j)ref=max(ref,sol(i|(1<<l),p[k][l],l));
	return ref+=1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n){
		cin>>p[i];
		f(j,0,n)p[i][j]-='0';
	}
	memset(s,-1,sizeof(s));
	cout<<sol(1,0,0);
	return 0;
}
