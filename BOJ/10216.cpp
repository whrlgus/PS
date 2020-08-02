#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

struct group{int x,y,r;}g[3000];
int p[3000],v[3000];

bool isValid(int a, int b){
	int dx=g[a].x-g[b].x, dy=g[a].y-g[b].y, dr=g[a].r+g[b].r;
	return dx*dx+dy*dy<=dr*dr;
}

int root(int x){
	return p[x]==x?x:root(p[x]);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		f(i,0,n)p[i]=i;
		f(i,0,n)cin>>g[i].x>>g[i].y>>g[i].r;
		f(i,0,n){
			int idx=1,mn=v[0]=root(i);
			f(j,i+1,n)if(isValid(i,j)){
				v[idx]=root(j);
				mn=min(mn,v[idx++]);
			}
			f(j,0,idx)p[v[j]]=mn;
		}
		int ans=0;
		f(i,0,n)if(p[i]==i)++ans;
		cout<<ans<<'\n';
		
	}
	return 0;
}
