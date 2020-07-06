#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int di[5][5]={{1,1,1,0,0},{1,2,2,0,1},{1,2,2,0,1},{1,1,1,0,0},{1,1,1,0,0}};
const int dj[5][5]={{0,1,2,1,2},{0,-1,0,-1,-1},{0,0,1,1,1},{-2,-1,0,-2,-1},{-1,0,1,-1,1}};
vector<vector<int>> b;
int n;

bool isInBoundary(int i, int j){
	return i>=0&&j>=0&&i<n&&j<n;
}

bool isEqual(int i, int j, int type){
	f(d,0,3){
		int ni=i+di[type][d],nj=j+dj[type][d];
		if(!isInBoundary(ni, nj)||b[ni][nj]!=b[i][j])return false;
	}
	return true;
}

bool canErase(int i, int j, int type){
	f(d,3,5){
		int ni=i+di[type][d],nj=j+dj[type][d];
		if(b[ni][nj]!=-1)return false;
	}
	return true;
}

void erase(int i, int j, int type){
	b[i][j]=(i==0||b[i-1][j]<0)?-1:0;
	
	f(d,0,3){
		int ni=i+di[type][d],nj=j+dj[type][d];
		if(b[ni-1][nj]<0){
			b[ni][nj]=-1;
			while(++ni<n&&b[ni][nj]==0)b[ni][nj]=-1;
		}else b[ni][nj]=0;
	}
}

bool check(int i, int j){
	f(type,0,5)if(isEqual(i, j, type)){
		if(canErase(i, j, type)){
			erase(i, j, type);
			return true;
		}
		break;
	}
	return false;
}

int solution(vector<vector<int>> board) {
	b.swap(board);
	n=b.size();
	f(j,0,n){
		int i=0;
		while(i<n&&!b[i][j])b[i][j]=-1,++i;
	}
	
	int answer = 0;
	f(i,0,n)f(k,0,2)f(j,0,n)if(b[i][j]>0&&check(i,j))++answer;
	return answer;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout<<solution({
		{0,0,0,0,0,0,0,0,0,0},
		{7,0,0,0,0,0,0,0,0,0},
		{7,0,6,0,0,0,0,0,0,0},
		{7,7,6,0,0,0,0,0,0,0},
		{0,6,6,0,0,0,4,0,0,0},
		{0,0,0,0,0,4,4,0,0,0},
		{0,0,0,0,3,0,4,0,0,0},
		{0,0,0,2,3,0,0,0,5,5},
		{1,2,2,2,3,3,0,0,0,5},
		{1,1,1,0,0,0,0,0,0,5}
	});
	return 0;
}
