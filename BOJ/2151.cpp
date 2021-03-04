#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;
struct info{int i,j,d,cnt;};
//좌우상하
int n,di[]={0,0,-1,1},dj[]={-1,1,0,0},nd[2][4]={{2,3,0,1},{3,2,1,0}};
char b[50][51];
bool vis[50][50];

bool inBound(int i,int j){
	return i>=0&&j>=0&&i<n&&j<n;
}

int sol(int i,int j,int d){
	memset(vis,0,sizeof(vis));
	int ans=0;
	queue<info> q;
	q.push({i,j,d,0});
	while(!q.empty()){
		int size=q.size();
		while(size--){
			info tmp=q.front();q.pop();
			while(1){
				tmp.i+=di[tmp.d];
				tmp.j+=dj[tmp.d];
				if(!inBound(tmp.i,tmp.j)||b[tmp.i][tmp.j]=='*'||vis[tmp.i][tmp.j])break;
				if(b[tmp.i][tmp.j]=='#')return ans;
				if(b[tmp.i][tmp.j]=='!'){
					vis[tmp.i][tmp.j]=true;
					f(t,0,2)q.push({tmp.i,tmp.j,nd[t][tmp.d],tmp.cnt+1});
				}
			}
		}
		++ans;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n)cin>>b[i];
	f(i,0,n)f(j,0,n)if(b[i][j]=='#'){
		b[i][j]='*';
		int mn=2500;
		f(d,0,4){
			int ni=i+di[d],nj=j+dj[d];
			if(inBound(ni,nj)&&b[ni][nj]!='*'){
				int tmp=sol(i,j,d);
				if(tmp!=-1)mn=min(mn,tmp);
			}
		}
		cout<<mn;
		return 0;
	}
	return 0;
}
