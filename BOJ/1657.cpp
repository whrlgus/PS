#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MXN=14;
int n,m,a[MXN][MXN],s[MXN][MXN][1<<MXN];
int price[5][5]={
	{10,8,7,5,1},
	{8,6,4,3,1},
	{7,4,3,2,1},
	{5,3,2,2,1},
	{1,1,1,1,0}
};

int sol(int i,int j,int k){
	if(i==n)return 0;
	if(j==m)return sol(i+1,0,k);
	int &ref=s[i][j][k];
	if(ref!=-1)return ref;
	
	ref=sol(i,j+1,k>>1);
	if(k&1)return ref;
	
	if(j!=m-1&&!(k&2))ref=max(ref,sol(i,j+2,k>>2)+price[a[i][j]][a[i][j+1]]);
	if(i!=n-1)ref=max(ref,sol(i,j+1,(k>>1)|(1<<(m-1)))+price[a[i][j]][a[i+1][j]]);
	
	return ref;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	f(i,0,n){
		char tmp[MXN+1];cin>>tmp;
		f(j,0,m)a[i][j]=tmp[j]=='F'?4:tmp[j]-'A';
	}
	memset(s,-1,sizeof(s));
	cout<<sol(0,0,0);
	
	return 0;
}
