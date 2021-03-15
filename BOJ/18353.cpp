#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	vector<int> v;
	f(i,0,n){
		int num;cin>>num;
		num=-num;
		int idx=lower_bound(v.begin(),v.end(),num)-v.begin();
		if(idx==v.size())v.push_back(num);
		else v[idx]=num;
	}
	cout<<n-v.size();
	return 0;
}
