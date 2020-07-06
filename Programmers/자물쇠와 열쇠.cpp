#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int m,n;

bool isInBoundary(int i, int j){
	return i>=0&&j>=0&&i<m&&j<m;
}

bool check(vector<vector<int>> &key, vector<vector<int>> &lock, int di, int dj){
	f(i,0,n)f(j,0,n){
		int keyI=i+di,keyJ=j+dj;
		int tmp=isInBoundary(keyI,keyJ)?key[keyI][keyJ]^lock[i][j]:lock[i][j];
		if(!tmp)return false;
	}
	return true;
}

void rotate(vector<vector<int>> &key){
	vector<vector<int>> copy=key;
	f(i,0,m)f(j,0,m)key[i][j]=copy[j][m-i-1];
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	n=lock.size();
	m=key.size();
	int from=-n+1;
	if(check(key,lock,m,m))return true;
	f(k,0,4){
		rotate(key);
		f(i,from,m)f(j,from,m)if(check(key,lock,i,j))return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout<<solution({{0, 0, 0}, {1, 0, 0}, {0, 1, 1}},	{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}});
	return 0;
}
