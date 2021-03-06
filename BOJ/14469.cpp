#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

typedef pair<int,int> pii;
int n;
pii p[100];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n)cin>>p[i].first>>p[i].second;
	sort(p,p+n);
	
	int ans=0;
	f(i,0,n){
		if(ans<p[i].first)ans=p[i].first;
		ans+=p[i].second;
	}
	cout<<ans;
	
	return 0;
}
