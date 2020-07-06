#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;
typedef long long ll;
pair<int,int> p[100000];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	ll total=0;
	f(i,0,n)cin>>p[i].first>>p[i].second,total+=p[i].second;
	sort(p,p+n);
	ll tmp=0;
	f(i,0,n)if((tmp+=p[i].second)*2>=total){
		cout<<p[i].first;
		break;
	}
	return 0;
}
