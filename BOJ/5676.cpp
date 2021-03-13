#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
#define fr(i,l,r) for(int i=l;i>=r;--i)
using namespace std;

int n,k,t[1<<18];

void update(int i,int v){
	if(v)v=v>0?1:-1;
	for(t[i+=n]=v;i>1;i>>=1)t[i>>1]=t[i]*t[i^1];
}

int query(int i,int j){
	int ret=1;
	for(i+=n,j+=n;i<j;i>>=1,j>>=1){
		if(i&1)ret*=t[i++];
		if(j&1)ret*=t[--j];
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while(cin>>n>>k){
		f(i,0,n){
			int tmp;cin>>tmp;
			if(tmp)tmp=tmp>0?1:-1;
			t[i+n]=tmp;
		}
		fr(i,n-1,1)t[i]=t[i<<1]*t[i<<1|1];
		while(k--){
			char c;
			int a,b;
			cin>>c>>a>>b;
			if(c=='C')update(a-1,b);
			else{
				int ret=query(a-1,b);
				cout<<(ret==0?'0':(ret>0?'+':'-'));
			}
		}
		cout<<'\n';
	}

	return 0;
}
