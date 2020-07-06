#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int INF=125;
int di[]={0,0,0,0,1,-1},dj[]={0,0,1,-1,0,0},dk[]={1,-1,0,0,0,0},m[5],ans=INF;
bool board[5][5][5],vis[5][5][5],used[5];
struct pos{int i,j,k;};

void rotate(int i){
	bool tmp[5][5];
	f(j,0,5)f(k,0,5)tmp[j][k]=board[i][j][k];
	f(j,0,5)f(k,0,5)board[i][j][k]=tmp[k][4-j];
}

int minDist(){
	queue<pos> q;
	q.push({0,0,0});
	memset(vis,false,sizeof(vis));
	vis[0][0][0]=true;
	
	int dist=0;
	while(!q.empty()){
		int size=q.size();
		while(size--){
			pos p=q.front();q.pop();
			if(p.i==4&&p.j==4&&p.k==4){
                if(dist==12) exit(0*puts("12"));
                return dist;
            }
			f(d,0,6){
				int i=p.i+di[d],j=p.j+dj[d],k=p.k+dk[d];
				if(i>=0&&j>=0&&k>=0&&i<5&&j<5&&k<5&&board[m[i]][j][k]&&!vis[i][j][k]){
					vis[i][j][k]=true;
					q.push({i,j,k});
				}
			}
		}
		if(++dist>=ans)break;
	}
	return INF;
}

void sol(int n){
	if(n==5){
		ans=min(ans,minDist());
		return;
	}
	f(i,0,5){
		if(used[i])continue;
		m[i]=n;
		used[i]=true;
		f(j,0,4){
			rotate(n);
			if((i==0&&!board[n][0][0])||(i==4&&!board[n][4][4]))continue;
			sol(n+1);
		}
		used[i]=false;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f(i,0,5)f(j,0,5)f(k,0,5)cin>>board[i][j][k];
	sol(0);
	cout<<(ans==INF?-1:ans);
	return 0;
}
