#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n,a[11][11],s[11][11][1<<11];
int price[4][4]={
	{100,70,40,0},
	{70,50,30,0},
	{40,30,20,0},
	{0,0,0,0}
};

int sol(int i,int j,int k){
	if(i==n)return 0;
	if(j==n)return sol(i+1,0,k);
	int &ref=s[i][j][k];
	if(ref!=-1)return ref;
	
	ref=sol(i,j+1,k>>1);
	if(k&1)return ref;
	
	if(j!=n-1&&!(k&2))ref=max(ref,sol(i,j+2,k>>2)+price[a[i][j]][a[i][j+1]]);
	if(i!=n-1)ref=max(ref,sol(i,j+1,(k>>1)|(1<<(n-1)))+price[a[i][j]][a[i+1][j]]);
	
	return ref;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n){
		char tmp[12];cin>>tmp;
		f(j,0,n)a[i][j]=tmp[j]=='F'?3:tmp[j]-'A';
	}
	memset(s,-1,sizeof(s));
	cout<<sol(0,0,0);
	
	return 0;
}
