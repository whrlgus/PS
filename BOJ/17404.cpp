#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int INF=1e9;
int n,p[1000][3],s[1000][3];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n;
	f(i,0,n)cin>>p[i][0]>>p[i][1]>>p[i][2];
	
	int ans=INF;
	f(i,0,3){
		s[0][0]=s[0][1]=s[0][2]=INF;
		s[0][i]=p[0][i];
		
		f(j,1,n)f(k,0,3)s[j][k]=min(s[j-1][(k+1)%3],s[j-1][(k+2)%3])+p[j][k];
		
		f(j,0,3)if(i!=j)ans=min(ans,s[n-1][j]);
	}
	cout<<ans;
	return 0;
}
