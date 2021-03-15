#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	vector<int> v;
	int n;cin>>n;
	while(n--){
		int num;cin>>num;
		int idx=lower_bound(v.begin(),v.end(),num)-v.begin();
		if(idx==v.size())v.push_back(num);
		else v[idx]=num;
	}
	cout<<v.size();
	return 0;
}
