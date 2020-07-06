#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;
int n,a[(int)1e5],s[2];

void sol(){
	int l=0,r=n-1,mn=2e9;
	while(l<r){
		int sum=a[l]+a[r];
		int tmp=abs(sum);
		if(mn>tmp)s[0]=l,s[1]=r,mn=tmp;
		if(!sum)return;
		sum>0?--r:++l;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n)cin>>a[i];
	sort(a,a+n);
	sol();
	cout<<a[s[0]]<<' '<<a[s[1]];
	return 0;
}
