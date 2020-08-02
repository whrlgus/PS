#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int v[501];
struct info{
	int idx,ind;
	bool operator< (const info& oth)const{
		return ind<oth.ind;
	}
}u[501];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		f(i,1,n){
			int tmp;cin>>tmp;
			u[tmp].idx=tmp;
			u[tmp].ind=i;
		}
		memset(v,0,sizeof(v));
		int m;cin>>m;
		while(m--){
			int a,b;cin>>a>>b;
			if(u[a]<u[b])++v[a],--v[b];
			else --v[a],++v[b];
		}
		f(i,1,n)u[i].ind+=v[i];
		sort(u+1,u+1+n);
		bool poss=true;
		f(i,1,n)if(u[i].ind!=i){
			poss=false;
			break;
		}
		if(!poss)cout<<"IMPOSSIBLE";
		else f(i,1,n)cout<<u[i].idx<<' ';
		cout<<'\n';
	}
	return 0;
}
