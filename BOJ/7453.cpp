#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;
const int MAXN=4000;
int n,idx,a[MAXN][4],b[MAXN*MAXN],c[MAXN*MAXN];
long long ans;

void foo(int k,int *arr){
	idx=0;
	f(i,0,n)f(j,0,n)arr[idx++]=a[i][k]+a[j][k+1];
	sort(arr, arr+idx);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n)f(j,0,4)cin>>a[i][j];
	
	foo(0,b);
	foo(2,c);
	
	f(i,0,idx)ans+=upper_bound(c, c+idx, -b[i])-lower_bound(c, c+idx, -b[i]);
	cout<<ans;
	
	return 0;
}
