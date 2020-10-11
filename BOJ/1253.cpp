#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n,a[2000];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n)cin>>a[i];
	sort(a,a+n);
	
	int ans=0;
	f(i,0,n){
		int l=0,r=n-1;
		while(l<r){
			if(l==i){++l;continue;}
			if(r==i){--r;continue;}
			int sum=a[l]+a[r];
			if(sum==a[i]){++ans;break;}
			sum<a[i]?++l:--r;
		}
	}
	cout<<ans;
	
	return 0;
}
