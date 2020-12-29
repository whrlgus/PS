#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MOD=9901;
int n,m,s[14*14][1<<14];

int sol(int i,int j){
	if(i==n*m)
		return j==0;
	
	int &ref=s[i][j];
	if(ref!=-1)return ref;
	
	if(j&1)ref=sol(i+1,j>>1);
	else{
		ref=sol(i+1,(j>>1)|(1<<(m-1)));
		if(!((j>>1)&1)&&(i+1)%m)ref=(ref+sol(i+2,(j>>2)))%MOD;
	}
	return ref;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	memset(s,-1,sizeof(s));
	cout<<sol(0,0);
	
	return 0;
}
