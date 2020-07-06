#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

string a[10000];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		f(i,0,n)cin>>a[i];
		sort(a,a+n);
		bool k=true;
		f(i,1,n)if(a[i].find(a[i-1])==0){
			k=false;
			break;
		}
		cout<<(k?"YES":"NO")<<'\n';
	}
	return 0;
}
