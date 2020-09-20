#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int josephus(int n,int k){
	if(n==1)return 1;
	return (josephus(n-1, k)+k-1)%n+1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,k,m;
	while(cin>>n>>k>>m&&n)cout<<(josephus(n-1,k)+m-1)%n+1<<'\n';
	return 0;
}
