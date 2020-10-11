#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MXN=10,INF=101;
bool a[MXN][MXN];
int mn=INF,cnt[6];

bool isValid(int r,int c,int d){
	int rsize=r+d,csize=c+d;
	if(rsize>10||csize>10)return false;
	f(i,r,rsize)f(j,c,csize)if(!a[i][j])return false;
	return true;
}

void setValue(int r,int c,int d,bool val){
	int rsize=r+d,csize=c+d;
	f(i,r,rsize)f(j,c,csize)a[i][j]=val;
}

void dfs(int i,int j,int k){
	if(i==MXN){
		mn=min(mn,k);
		return;
	}
	if(j==MXN)dfs(i+1,0,k);
	if(a[i][j]){
		f(d,1,6)if(cnt[d]&&isValid(i,j,d)){
			--cnt[d];
			setValue(i,j,d,false);
			dfs(i,j+d,k+1);
			++cnt[d];
			setValue(i,j,d,true);
		}
	}else dfs(i,j+1,k);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f(i,0,MXN)f(j,0,MXN)cin>>a[i][j];
	f(i,1,6)cnt[i]=5;
	dfs(0,0,0);
	cout<<(mn==INF?-1:mn);
	return 0;
}
