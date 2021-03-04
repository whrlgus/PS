#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;
int x,b;

void foo(int n){
	if(!n)return;
	int q=n/b,r=n%b;
	if(r<0){
		if(b<0)r-=b,q+=1;
		else r+=b,q-=1;
	}
	foo(q);
	cout<<r;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>x>>b;
	if(x==0)cout<<0;
	else if(x<0&&b>0){
		cout<<'-';
		foo(-x);
	}else foo(x);

	
	return 0;
}
