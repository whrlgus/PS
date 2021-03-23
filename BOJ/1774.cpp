#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
#define fr(i,l,r) for(int i=l;i>=r;--i)
using namespace std;

int N,M,a[1001][2];
double d[1001][1001],s[1001];
bool chk[1001];

double dist(int i,int j){
	long long x=a[i][0]-a[j][0],y=a[i][1]-a[j][1];
	return sqrt(x*x+y*y);
}

double sol(){
	s[0]=2e6;
	s[1]=0;
	int cnt=N;
	double ret=0;
	while(cnt--){
		int v=0;
		f(i,1,N)if(!chk[i]&&s[v]>s[i])v=i;
		chk[v]=true;
		ret+=s[v];
		
		f(i,1,N)if(!chk[i])s[i]=min(s[i],d[i][v]);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N>>M;
	f(i,1,N){
		cin>>a[i][0]>>a[i][1];
		s[i]=2e6;
		fr(j,i-1,1)d[i][j]=d[j][i]=dist(i,j);
	}
	f(k,1,M){
		int i,j;cin>>i>>j;
		d[i][j]=d[j][i]=0;
	}
	
	cout<<setprecision(2)<<fixed<<sol();
	return 0;
}

