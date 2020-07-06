#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;
int n,m,ans[3],a[50][50],b[50][50],cnt[2501],di[]={0,-1,0,1},dj[]={-1,0,1,0};

bool isValid(int i,int j){
	return i>=0&&j>=0&&i<m&&j<n;
}

int count(int i,int j){
	int ret=1;
	b[i][j]=ans[0];
	f(d,0,4)if(!((a[i][j]>>d)&1)){
		int ni=i+di[d],nj=j+dj[d];
		if(!isValid(ni,nj)||b[ni][nj])continue;
		ret+=count(ni,nj);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	f(i,0,m)f(j,0,n)cin>>a[i][j];
	
	f(i,0,m)f(j,0,n)if(!b[i][j])++ans[0],ans[1]=max(ans[1],cnt[ans[0]]=count(i,j));
	
	f(i,0,m)f(j,0,n)f(d,0,4)if((a[i][j]>>d)&1){
		int ni=i+di[d],nj=j+dj[d];
		if(!isValid(ni,nj))continue;
		int tmp=cnt[b[i][j]]+(b[i][j]==b[ni][nj]?0:cnt[b[ni][nj]]);
		if(ans[2]<tmp)ans[2]=tmp;
	}
	f(i,0,3)cout<<ans[i]<<'\n';
	return 0;
}
