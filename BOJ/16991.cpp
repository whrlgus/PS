#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const double INF=17*3000;
int n,pos[16][2],finish;
double dp[1<<16][16],d[16][16];

double sol(int state,int curr){
	double &ref=dp[state][curr];
	if(ref)return ref;
	if(state==finish)return ref=d[0][curr];
	
	ref=INF;
	f(i,0,n)if(!((state>>i)&1))ref=min(ref,sol(state|(1<<i),i)+d[curr][i]);
	return ref;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n)cin>>pos[i][0]>>pos[i][1];
	
	finish=(1<<n)-1;
	f(i,0,n)f(j,0,n){
		int a=pos[i][0]-pos[j][0],b=pos[i][1]-pos[j][1];
		d[i][j]=sqrt(a*a+b*b);
	}
	
	cout<<fixed<<setprecision(6)<<sol(1,0);
	return 0;
}
