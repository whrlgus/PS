#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int k,g[13],total;
bool s[2600001];

int sol(int i, int a){
	int ret=0;
	if(!s[abs(a)])s[abs(a)]=true,++ret;
	if(i==k)return ret;
	return ret+sol(i+1, a+g[i])+sol(i+1, a-g[i])+sol(i+1, a);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>k;
	f(i,0,k)cin>>g[i],total+=g[i];
	++total;
	cout<<total-sol(0,0);
	return 0;
}
