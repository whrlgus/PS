#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int INF=1e5+1;
int m,f,r,c,s[100][101][101],a[100][2];

int sol(int i,int j,int k,int l){
	if(i==r)return j||k?INF:0;
	int &ref=s[i][j][k];
	if(ref!=-1)return ref;
	
	ref=sol(i+1,j,k,l);
	if(l>0&&a[i][0]>1)ref=min(ref,sol(i+1,j-1,k-1,l-1)+a[i][1]);
	int tmp=min(a[i][0],j);
	ref=min(ref,sol(i+1,j-tmp,k,min(l,min(j-tmp,k)))+a[i][1]);
	tmp=min(a[i][0],k);
	ref=min(ref,sol(i+1,j,k-tmp,min(l,min(j,k-tmp)))+a[i][1]);
	
	return ref;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>m>>f>>r>>c;
	f(i,0,r)cin>>a[i][0]>>a[i][1];
	memset(s,-1,sizeof(s));
	int ans=sol(0,m,f,c);
	if(ans==INF)cout<<"Impossible";
	else cout<<ans;
	
	return 0;
}
