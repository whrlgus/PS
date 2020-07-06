#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
#define fr(i,l,r) for(int i=l;i>=r;--i)
using namespace std;
typedef long long ll;
int n,a[5000],s[3];

void sol(){
	ll mn=3e9;
	fr(i,n-3,0){
		int l=i+1,r=n-1;
		while(l<r){
			ll sum=(ll)a[i]+a[l]+a[r],tmp=abs(sum);
			if(mn>tmp)s[0]=i,s[1]=l,s[2]=r,mn=tmp;
			if(!sum)return;
			sum>0?--r:++l;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n)cin>>a[i];
	sort(a,a+n);
	sol();
	f(i,0,3)cout<<a[s[i]]<<' ';
	return 0;
}
