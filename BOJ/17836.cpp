#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int INF=1e4;
int N,M,T,a[100][100],s[100][100][2],di[]={1,-1,0,0},dj[]={0,0,1,-1};
struct info{int i,j,k;};

void sol(){
	queue<info> q;
	q.push({0,0,(a[0][0]==2?1:0)});
	int t=0;
	while(!q.empty()&&t<=T){
		int size=q.size();
		while(size--){
			int i=q.front().i,j=q.front().j,k=q.front().k;q.pop();
			if(t>=s[i][j][k])continue;
			s[i][j][k]=t;
			if(i==N-1&&j==M-1)continue;
			if(a[i][j]==2)k=1,s[i][j][1]=t;
			f(d,0,4){
				int ni=i+di[d],nj=j+dj[d];
				if(ni<0||nj<0||ni>=N||nj>=M||(!k&&a[i][j]==1))continue;
				q.push({ni,nj,k});
			}
		}
		++t;
	}
	int ans=min(s[N-1][M-1][0],s[N-1][M-1][1]);
	if(ans==INF)cout<<"Fail";
	else cout<<ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N>>M>>T;
	f(i,0,N)f(j,0,M)cin>>a[i][j],s[i][j][0]=s[i][j][1]=INF;
	sol();
	return 0;
}
