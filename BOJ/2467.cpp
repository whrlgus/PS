#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;
int a[(int)1e5];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	f(i,0,n)cin>>a[i];
	sort(a,a+n);
	int l=0,r=n-1,ans[2],mn=2e9,tmp[2];
	while(l<r){
		int prev=abs(a[l]+a[r]),curr;
		tmp[0]=a[l];
		tmp[1]=a[r];
		while(l+1<r&&prev>=(curr=abs(a[l]+a[r-1]))){
			--r;
			prev=curr;
			tmp[0]=a[l];
			tmp[1]=a[r];
		}
		if(mn>prev){
			mn=prev;
			ans[0]=tmp[0];
			ans[1]=tmp[1];
		}
		++l;
	}
	cout<<ans[0]<<' '<<ans[1];
	return 0;
}
