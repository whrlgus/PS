#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

typedef long long ll;

ll n,x,y;
int k,q;

ll sol(){
	cin>>x>>y;
	if(k==1)return abs(x-y);
	ll ret=0;
	while(x!=y){
		x>y?x=(x-2)/k+1:y=(y-2)/k+1;
		++ret;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k>>q;
	while(q--)cout<<sol()<<'\n';
	return 0;
}
