#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int MAXN=1e5+1;
int heap[MAXN];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	f(i,2,n){
		int j=i-1;
		while(j>>1)heap[j]=heap[j>>1],j>>=1;
		heap[1]=i;
	}
	heap[n]=1;
	f(i,1,n)cout<<heap[i]<<' ';
	return 0;
}
