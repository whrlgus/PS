#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;cin>>t;
	while(t--){
		int h,w,n;cin>>h>>w>>n;
		int tmp=n%h;
		printf("%d%02d\n",tmp==0?h:tmp,n/h+(tmp==0?0:1));
	}
	return 0;
}
