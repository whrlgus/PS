#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

typedef pair<int,int> pii;
int R,C,N,di[]={0,0,1,-1},dj[]={1,-1,0,0};
char b[101][101];

bool foo(int r,int c){
	if(r<=1||r>R||c<0||c>=C||b[r][c]=='.')return false;
	
	stack<pii> s;
	vector<pii> v;
	bool vis[101][100]{};
	
	s.push({r,c});
	v.push_back({r,c});
	vis[r][c]=true;
	
	while(!s.empty()){
		pii tmp=s.top();s.pop();
		f(d,0,4){
			int ni=tmp.first+di[d],nj=tmp.second+dj[d];
			if(ni<1||ni>R||nj<0||nj>=C||vis[ni][nj]||b[ni][nj]=='.')continue;
			if(ni==1)return false;
			
			s.push({ni,nj});
			v.push_back({ni,nj});
			vis[ni][nj]=true;
		}
	}
	
	int mn=R;
	for(auto &ele:v){
		int i=ele.first,j=ele.second,tmp=0;
		while(--i>0&&b[i][j]=='.')++tmp;
		if(vis[i][j])continue;
		mn=min(mn,tmp);
	}
	
	sort(v.begin(),v.end());
	for(auto &ele:v){
		int i=ele.first,j=ele.second;
		b[i][j]='.';
		b[i-mn][j]='x';
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>R>>C;
	f(i,0,R)cin>>b[R-i];
	cin>>N;
	
	int r,c,end,k;
	f(i,0,N){
		cin>>r;
		if(i&1)c=C-1,end=-1,k=-1;
		else c=0,end=C,k=1;
		
		while(c!=end&&b[r][c]=='.')c+=k;
		if(c==end)continue;
		
		b[r][c]='.';
		foo(r+1,c)||foo(r,c+k)||foo(r-1,c);
	}
	
	f(i,0,R)cout<<b[R-i]<<'\n';
	return 0;
}
