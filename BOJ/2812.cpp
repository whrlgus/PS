#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n,k;
char p[(int)5e5+1];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k>>p;
	int top=-1;
	f(i,0,n){
		while(top!=-1&&k&&p[top]<p[i])--k,--top;
		p[++top]=p[i];
	}
	p[top-k+1]=0;
	cout<<p;
	
	return 0;
}
