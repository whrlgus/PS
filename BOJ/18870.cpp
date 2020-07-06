#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int a[(int)1e6],b[(int)1e6],n,idx;
set<int> s;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n){
		cin>>a[i];
		if(!s.count(a[i]))b[idx++]=a[i],s.insert(a[i]);
	}
	sort(b,b+idx);
	f(i,0,n)cout<<lower_bound(b,b+idx,a[i])-b <<' ';
	return 0;
}
