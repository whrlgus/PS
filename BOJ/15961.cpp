#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n,d,k,c,a[3003001],b[3001];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>d>>k>>c;
	f(i,0,n)cin>>a[i];
	int mxCnt=0;
	f(i,0,k){
		if(++b[a[i]]==1)++mxCnt;
		a[n+i]=a[i];
	}
	--n;
	int cnt=mxCnt;
	f(i,0,n){
		if(--b[a[i]]==0)--cnt;
		if(++b[a[i+k]]==1)++cnt;
		int tmp=(b[c]==0?1:0);
		if(mxCnt<cnt+tmp)mxCnt=cnt+tmp;
	}
	cout<<mxCnt;
	
	return 0;
}
