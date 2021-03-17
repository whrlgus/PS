#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MAXN=1e5;
int n,idx[MAXN+1],order[MAXN];

void sol(int i,int l,int r){
	if(l>r)return;
	cout<<order[i]<<' ';
	int tmp=idx[order[i]];
	sol(i-r+tmp-1,l,tmp-1);
	sol(i-1,tmp+1,r);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n){
		int tmp;cin>>tmp;
		idx[tmp]=i;
	}
	f(i,0,n)cin>>order[i];
	sol(n-1,0,n-1);
	
	return 0;
}

