#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int a[6]={5,3,4,1,2,0},b[][4]={{1,2,3,4},{0,2,4,5},{0,1,3,5},{0,2,4,5},{0,1,3,5},{1,2,3,4}};
int n,p[10000][6];

int sol(int i){
	int sum=0,j=0;
	while(true){
		int mx=0;
		f(k,0,4)mx=max(mx,p[j][b[i][k]]);
		sum+=mx;
		
		if(j==n-1)break;
		f(k,0,6)if(p[j+1][k]==p[j][a[i]]){
			i=k;
			break;
		}
		++j;
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n)f(j,0,6)cin>>p[i][j];
	
	int ans=0;
	f(i,0,6)ans=max(ans,sol(i));
	cout<<ans;
	
	return 0;
}
