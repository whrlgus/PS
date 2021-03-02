#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

typedef pair<int,int> pii;
const int INF=1000;
int n,m,mn,dest[2],s[2][2],e[2][2];
int di[]={0,0,1,-1},dj[]={1,-1,0,0};
pii pre[101][101];
bool vis[101][101];

int bfs(int k){
	int len=0;
	queue<pii> q;
	q.push({s[k][0],s[k][1]});
	vis[s[k][0]][s[k][1]]=true;
	
	while(!q.empty()){
		++len;
		int size=q.size();
		while(size--){
			pii tmp=q.front();q.pop();
			
			f(d,0,4){
				int i=tmp.first+di[d],j=tmp.second+dj[d];
				if(i<0||j<0||i>n||j>m||vis[i][j])continue;
				pre[i][j]={tmp.first, tmp.second};
				vis[i][j]=true;
				if(i==e[k][0]&&j==e[k][1])return len;
				q.push({i,j});
			}
		}
	}
	return -1;
}

void visit(int i,int j){
	while(i>=0&&j>=0){
		vis[i][j]=true;
		pii &tmp=pre[i][j];
		i=tmp.first;
		j=tmp.second;
	}
}

int sol(int i){
	memset(vis,false,sizeof(vis));
	memset(pre,-1,sizeof(pre));
	vis[s[i^1][0]][s[i^1][1]]=vis[e[i^1][0]][e[i^1][1]]=true;
	if((mn=bfs(i))<0)return INF;
	
	memset(vis,false,sizeof(vis));
	visit(e[i][0],e[i][1]);
	
	int tmp=bfs(i^1);
	if(tmp<0)return INF;
	return mn+tmp;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	f(i,0,2){
		cin>>s[i][0]>>s[i][1];
		cin>>e[i][0]>>e[i][1];
	}
	
	int tmp=min(sol(0),sol(1));
	if(tmp==INF)cout<<"IMPOSSIBLE";
	else cout<<tmp;
	
	return 0;
}
