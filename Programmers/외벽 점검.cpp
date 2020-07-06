#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int ans,N,w[15],d[8],wSize,dSize;
bool vis[15];

int count(int from, int dist){
	vis[from]=true;
	int i=from+1;
	while(!vis[i%wSize]&&(N+w[i%wSize]-w[from])%N<=dist)++i;
	vis[from]=false;
	return i-from;
}

void setVis(int i, int cnt, bool val){
	while(cnt--)vis[(i++)%wSize]=val;
}

void repair(int idx, int remains){
	if(!remains){
		ans=min(ans,dSize-idx-1);
		return;
	}
	
	int mxCnt=0,cnt[15];
	f(i,0,wSize)if(!vis[i])mxCnt=max(mxCnt,cnt[i]=count(i,d[idx]));
	if(mxCnt*(idx+1)<remains)return;
	
	f(i,0,wSize)if(!vis[i]){
		setVis(i,cnt[i],true);
		repair(idx-1, remains-cnt[i]);
		setVis(i,cnt[i],false);
	}
}

int solution(int n, vector<int> weak, vector<int> dist) {
	N=n;
	f(i,0,weak.size())w[i]=weak[i];
	f(i,0,dist.size())d[i]=dist[i];
	wSize=weak.size();
	dSize=dist.size();
	ans=dSize+1;
	repair(dSize-1,wSize);
	return ans==dSize+1?-1:ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout<<solution(12, {1, 5, 6, 10}, {1, 2, 3, 4});
	return 0;
}
