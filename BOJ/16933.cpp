#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int N,M,K,s[1001][1001],di[]={0,0,-1,1},dj[]={-1,1,0,0};
char B[1002][1002];
struct info{int i,j,k;};

int sol(){
	queue<info> q;
	q.push({1,1,0});
	int ans=1;
	while(!q.empty()){
		++ans;
		int size=q.size();
		while(size--){
			info tmp=q.front();q.pop();
			f(d,0,3){
				int ni=tmp.i+di[d],nj=tmp.j+dj[d];
				if(!B[ni][nj])continue;
				if(ni==N&&nj==M)return ans;
				
				int nk=(B[ni][nj]=='1')+tmp.k;
				if(nk>K||s[ni][nj]<=nk)continue;
				
				if(B[ni][nj]=='1'&&(ans&1)){
					q.push(tmp);
					continue;
				}
				
				s[ni][nj]=nk;
				q.push({ni,nj,nk});
			}
		}
	}
	
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N>>M>>K;
	f(i,1,N){
		cin>>(B[i]+1);
		f(j,1,M)s[i][j]=11;
	}
	cout<<(N==1&&M==1?1:sol());
	return 0;
}

