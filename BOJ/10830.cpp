#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;

int n;
vvi a,b;
void foo(vvi &p, vvi &q){
	vvi tmp(n,vi(n));
	f(i,0,n)f(j,0,n)f(k,0,n)tmp[i][j]+=(p[i][k]*q[k][j]);
	f(i,0,n)f(j,0,n)q[i][j]=tmp[i][j]%1000;
}

void boo(ll i){
	if(i==1)return;
	
	boo(i>>1);
	foo(b,b);
	if(i&1)foo(a,b);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll tmp;
	cin>>n>>tmp;
	vvi(n,vi(n)).swap(a);
	vvi(n,vi(n)).swap(b);
	f(i,0,n)f(j,0,n)cin>>a[i][j],b[i][j]=a[i][j]%1000;
	
	boo(tmp);
	f(i,0,n){
		f(j,0,n)cout<<b[i][j]<<' ';
		cout<<'\n';
	}
	return 0;
}
