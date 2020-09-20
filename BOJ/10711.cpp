#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int h,w,di[]={-1,-1,-1,0,0,1,1,1},dj[]={-1,0,1,-1,1,-1,0,1};
char p[1002][1002];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>h>>w;
	queue<pair<int,int>> q;
	f(i,1,h){
		cin>>(p[i]+1);
		f(j,1,w)if(p[i][j]=='.')q.push({i,j});
	}
	int ans=0;
	while(true){
		int size=q.size();
		while(size--){
			int i=q.front().first,j=q.front().second;q.pop();
			f(d,0,7){
				int ni=i+di[d],nj=j+dj[d];
				if(--p[ni][nj]=='0')q.push({ni,nj});
			}
		}
		if(q.empty())break;
		++ans;
	}
	cout<<ans;
	return 0;
}
