#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int n,m,w,size,edge[5201][3],d[501];

bool sol(){
	f(i,1,n)d[i]=5e6;
	d[1]=0;
	int cnt=size;
	bool updated;
	while(cnt--){
		updated=false;
		f(j,1,size){
			int tmp=d[edge[j][0]]+edge[j][2];
			if(d[edge[j][1]]>tmp){
				if(edge[j][1]==1)return true;
				d[edge[j][1]]=tmp,updated=true;
			}
		}
		if(!updated)return false;
	}
	return updated;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n>>m>>w;
		size=0;
		while(m--){
			int s,e,t;cin>>s>>e>>t;
			size+=2;
			edge[size-1][0]=edge[size][1]=s;
			edge[size-1][1]=edge[size][0]=e;
			edge[size-1][2]=edge[size][2]=t;
		}
		while(w--){
			int s,e,t;cin>>s>>e>>t;
			++size;
			edge[size][0]=s;
			edge[size][1]=e;
			edge[size][2]=-t;
		}
		
		cout<<(sol()?"YES":"NO")<<'\n';
	}
	return 0;
}
