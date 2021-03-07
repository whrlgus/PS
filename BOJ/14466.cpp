#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

pair<int,int> cow[101];
set<vector<int>> s;
int n,k,r,p[101][101],no,di[]={0,0,-1,1},dj[]={-1,1,0,0};

bool inBound(int i,int j){
	return 1<=i&&i<=n&&1<=j&&j<=n;
}

bool hasBridge(vector<int> v){
	return s.find(v)!=s.end()||s.find({v[2],v[3],v[0],v[1]})!=s.end();
}

void visit(int i,int j){
	p[i][j]=no;
	f(d,0,3){
		int ni=i+di[d],nj=j+dj[d];
		if(inBound(ni,nj)&&!p[ni][nj]&&!hasBridge({i,j,ni,nj}))visit(ni,nj);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k>>r;
	while(r--){
		int a,b,c,d;cin>>a>>b>>c>>d;
		s.insert({a,b,c,d});
	}
	f(i,1,k)cin>>cow[i].first>>cow[i].second;
	
	f(i,1,n)f(j,1,n)if(!p[i][j]){
		++no;
		visit(i,j);
	}
	
	int ans=0;
	f(i,1,k)f(j,i+1,k)if(p[cow[i].first][cow[i].second]!=p[cow[j].first][cow[j].second])++ans;
	cout<<ans;
	
	return 0;
}
