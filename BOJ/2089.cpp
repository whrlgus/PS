#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long n,i=1,j=1,l=0,r=1;
	cin>>n;

	while(n<l||n>r){
		j<<=1;
		i&1?(l-=j):(r+=j);
		++i;
	}
	
	while(n){
		--i;
		long long tmp=n+(i&1?j:-j);
		if(l<=tmp&&tmp<=r){
			cout<<1;
			n=tmp;
		}else cout<<0;
		i&1?(l+=j):(r-=j);
		j>>=1;
	}
	while(i--)cout<<0;
	
	
	return 0;
}
