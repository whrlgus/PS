#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n,m,a[(int)5e5];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n)cin>>a[i];
	sort(a,a+n);
	cin>>m;
	while(m--){
		int num;cin>>num;
		cout<<upper_bound(a, a+n, num)-lower_bound(a, a+n, num)<<' ';
	}
	return 0;
}
