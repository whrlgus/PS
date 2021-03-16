#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int h,w,s[102][102],di[]={0,0,-1,1},dj[]={-1,1,0,0};
char B[102][102];
bool vis[102][102];
struct info{int i,j,k;};

void bfs(int i,int j){
	memset(vis,false,sizeof(vis));
	deque<info> dq;
	dq.push_back({i,j,0});
	vis[i][j]=true;
	while(!dq.empty()){
		info tmp=dq.front();dq.pop_front();
		int &ref=s[tmp.i][tmp.j];
		if(ref<0)ref=0;
		ref+=tmp.k;
		f(d,0,3){
			int ni=tmp.i+di[d],nj=tmp.j+dj[d];
			if(ni<0||nj<0||ni>h||nj>w||vis[ni][nj]||B[ni][nj]=='*')continue;
			if(B[ni][nj]=='#')dq.push_back({ni,nj,tmp.k+1});
			else dq.push_front({ni,nj,tmp.k});
			vis[ni][nj]=true;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;cin>>t;
	while(t--){
		memset(s,-1,sizeof(s));
		cin>>h>>w;
		
		vector<pair<int,int>> v;
		v.push_back({0,0});
		f(i,1,h){
			cin>>B[i]+1;
			f(j,1,w)if(B[i][j]=='$')v.push_back({i,j});
		}
		++w;++h;
		f(i,0,w)B[0][i]=B[h][i]='.';
		f(i,0,h)B[i][0]=B[i][w]='.';
		
		for(auto ele:v)bfs(ele.first,ele.second);
		
		int ans=3e4;
		f(i,0,h)f(j,0,w)if(B[i][j]!='*'&&s[i][j]>=0){
			if(B[i][j]=='#')s[i][j]-=2;
			ans=min(ans,s[i][j]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}

