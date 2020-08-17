#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
#define mn(a,b,c) min(a,min(b,c))
using namespace std;

const int INF=2e4+10;
int n,w,p[2][10001],s[2][5],l,r;

void sol(bool d, bool e){
	int a=(p[0][0]+p[1][0])<=w, b=(p[0][0]+p[0][1])<=w, c=(p[1][0]+p[1][1])<=w;
	s[0][0]=2;
	s[0][1]=1+!a;
	s[0][2]=b?2:INF;
	s[0][3]=c?2:INF;
	s[0][4]=b&&c?2:INF;
	
	if(d)s[0][2]=INF;
	if(e)s[0][3]=INF;
	if(d||e)s[0][1]=s[0][4]=INF;
	
	r=0;
	f(i,1,n){
		l=r;
		r^=1;

		a=(p[0][i]+p[1][i])<=w, b=(p[0][i]+p[0][i+1])<=w, c=(p[1][i]+p[1][i+1])<=w;
		
		int tmp=min(s[l][0],s[l][1])+2;
		s[r][0]=min(min(tmp,min(s[l][2],s[l][3])+1),s[l][4]);
		s[r][1]=tmp-a;
		s[r][2]=b?min(tmp,s[l][3]+1):INF;
		s[r][3]=c?min(tmp,s[l][2]+1):INF;
		s[r][4]=(b&&c)?tmp:INF;
	}
}



int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n>>w;
		f(i,0,2)f(j,0,n)cin>>p[i][j];
		p[0][n]=p[1][n]=0;
		
		
		int ans=0;
		sol(0,0);
		ans=min(s[r][0],s[r][1]);
		
		int a=(p[0][0]+p[0][n-1])<=w, b=(p[1][0]+p[1][n-1])<=w;
		if(a){
			sol(1,0);
			ans=min(ans,min(min(s[l][0],s[l][1])+1,s[l][3]));
		}
		if(b){
			sol(0,1);
			ans=min(ans,min(min(s[l][0],s[l][1])+1,s[l][2]));
		}
		if(a&&b){
			sol(1,1);
			ans=min(ans,min(s[l][0],s[l][1]));
		}
		cout<<ans<<'\n';
	}
	return 0;
}
