#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

struct robot{int i,j,k;};
int di[]={0,0,1,-1},dj[]={1,-1,0,0};
int rdi[][4]={{0,1,0,1},{0,-1,0,-1}}, rdj[][4]={{0,0,-1,-1},{0,0,1,1}};
int diadi[][4]={{1,0,1,0},{1,-1,1,-1}}, diadj[][4]={{1,1,-1,-1},{1,1,0,0}};
int n;
bool vis[101][101][2];
vector<vector<int>> b;

bool check(int i, int j){
	return i>=0&&j>=0&&i<n&&j<n&&!b[i][j];
}

bool isValid(int i, int j, int k){
	int ni=i+(k?1:0),nj=j+(k?0:1);
	return !vis[i][j][k]&&check(i, j)&&check(ni, nj);
}

int solution(vector<vector<int>> board) {
	b.swap(board);
	n=b.size();
	queue<robot> q;
	q.push({0,0,0});
	vis[0][0][0]=true;
	
	int answer = 0;
	while(!q.empty()){
		long long size=q.size();
		while(size--){
			robot &r=q.front();
			int i=r.i,j=r.j,k=r.k;
			q.pop();
			if((i==n-1&&j==n-2)||(i==n-2&&j==n-1))return answer;
			f(d,0,4){
				int ni=i+di[d],nj=j+dj[d];
				if(!isValid(ni,nj,k))continue;
				q.push({ni,nj,k});
				vis[ni][nj][k]=true;
			}
			k^=1;
			f(d,0,4){
				int ni=i+rdi[k][d],nj=j+rdj[k][d];
				if(!check(i+diadi[k][d],j+diadj[k][d])||!isValid(ni,nj,k))continue;
				q.push({ni,nj,k});
				vis[ni][nj][k]=true;
			}
		}
		++answer;
	}
    return -1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout<<solution({{0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0}});
	return 0;
}
