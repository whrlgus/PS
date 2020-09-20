#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int r,c,ans,di[]={-1,0,1};
char s[10000][501];

bool dfs(int i,int j){
	if(i<0||i>=r)return false;
	if(j==c){
		++ans;
		return true;
	}
	if(s[i][j]=='x')return false;
	s[i][j]='x';
	f(d,0,3)if(dfs(i+di[d],j+1))return true;

	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>r>>c;
	f(i,0,r)cin>>s[i];
	
	f(i,0,r)dfs(i,0);
	cout<<ans;
	
	return 0;
}
