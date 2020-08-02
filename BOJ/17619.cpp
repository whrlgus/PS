#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int MAXN=1e5+1;
struct bar{
	int no,x1,x2;
	bool operator< (const bar& oth)const{
		return x1<oth.x1;
	}
}b[MAXN];
int p[MAXN];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n,q,tmp;
	cin>>n>>q;
	f(i,1,n){
		p[i]=b[i].no=i;
		cin>>b[i].x1>>b[i].x2>>tmp;
	}
	sort(b+1,b+n+1);
	
	tmp=b[1].x2;
	int no=b[1].no;
	f(i,2,n){
		if(b[i].x1<=tmp)p[b[i].no]=no;
		else no=b[i].no;
		tmp=max(tmp,b[i].x2);
	}
	
	f(i,1,q){
		int u,v;cin>>u>>v;
		cout<<(p[u]==p[v])<<'\n';
	}
	
	return 0;
}
