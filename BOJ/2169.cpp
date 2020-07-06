#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
#define fr(i,l,r) for(int i=l;i>=r;--i)
using namespace std;
const int INF=-1e8;
const int MAXN=1001;
int n,m,a[MAXN],s[2][MAXN][3],idx;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	
	idx^=1;
	f(i,0,m)cin>>s[idx][i][0];
	f(i,1,m)s[idx][i][0]=s[idx][i][1]=s[idx][i][0]+s[idx][i-1][0];
	f(i,0,m)s[idx][i][2]=INF;
	s[0][0][1]=s[0][m-1][2]=s[1][0][1]=s[1][m-1][2]=INF;
	while(--n){
		f(i,0,m)cin>>a[i];
		idx^=1;
		s[idx][0][0]=a[0]+max(s[idx^1][0][0],s[idx^1][0][2]);
		f(i,1,m){
			s[idx][i][0]=a[i]+(max(s[idx^1][i][0],max(s[idx^1][i][1],s[idx^1][i][2])));
			s[idx][i][1]=a[i]+max(s[idx][i-1][0],s[idx][i-1][1]);
		}
		fr(i,m-2,0)s[idx][i][2]=a[i]+max(s[idx][i+1][0],s[idx][i+1][2]);
	}
	
	cout<<max(s[idx][m-1][0],s[idx][m-1][1]);
	return 0;
}
