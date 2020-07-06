#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;
typedef long long ll;
const int MAXN=40;
int n,s,a[MAXN],b[1<<(MAXN/2)],c[1<<(MAXN/2)],idx;

void foo(int *arr,int l,int r,int val){
	f(i,l,r){
		int tmp=val+a[i];
		arr[idx++]=tmp;
		foo(arr, i+1, r, tmp);
	}
}

int boo(int *arr,int l, int r){
	idx=0;
	foo(arr,l,r,0);
	sort(arr,arr+idx);
	return idx;
}

int count(int *arr,int len,int val){
	return upper_bound(arr, arr+len, val)-lower_bound(arr, arr+len, val);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>s;
	f(i,0,n)cin>>a[i];
	int lenB=boo(b, 0, n/2);
	int lenC=boo(c, n/2, n);

	long long ans=count(b, lenB, s)+count(c, lenC, s);
	f(i,0,lenB)ans+=count(c, lenC, s-b[i]);
	cout<<ans;

	return 0;
}

