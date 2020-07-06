#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MAXN=1e6;
int N,M,a[MAXN];

bool isValid(int h){
	long long sum=0;
	f(i,0,N)if(a[i]>h&&(sum+=a[i]-h)>=M)return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N>>M;
	f(i,0,N)cin>>a[i];
	
	int l=0,r=1e9;
	while(l+1<r){
		int mid=(l+r)>>1;
		(isValid(mid)?l:r)=mid;
	}
	cout<<l;
	return 0;
}
