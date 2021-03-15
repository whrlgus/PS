#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

const int INF=8e6+1;
int n,c,a[2000][2],s[2000];
bool vis[2000];

int dist(int i,int j){
	int t=a[i][0]-a[j][0],s=a[i][1]-a[j][1];
	return t*t+s*s;
}

ll sol(){
	priority_queue<pii> pq;
	pq.push({0,0});
	s[0]=0;
	ll ret=0;
	int cnt=0;
	while(!pq.empty()){
		pii tmp=pq.top();pq.pop();
		if(vis[tmp.second])continue;
		ret-=tmp.first;
		vis[tmp.second]=true;
		if(++cnt==n)break;
		
		int d;
		f(i,0,n)if(!vis[i]&&(d=dist(i,tmp.second))>=c&&s[i]>d){
			pq.push({-d,i});
			s[i]=d;
		}
	}
	
	return cnt==n?ret:-1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>c;
	f(i,0,n)cin>>a[i][0]>>a[i][1],s[i]=INF;
	
	cout<<sol();
	return 0;
}
