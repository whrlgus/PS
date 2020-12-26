#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a,b,c;cin>>a>>b>>c;
	cout<<max(c-b,b-a)-1;
	return 0;
}
