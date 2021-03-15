#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int N=1e5+1;
int a[N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	f(i,0,n){
		int tmp;cin>>tmp;
		a[tmp]=i;
	}
	
	vector<int> v;
	while(n--){
		int num;cin>>num;
		int idx=lower_bound(v.begin(),v.end(),a[num])-v.begin();
		if(idx==v.size())v.push_back(a[num]);
		else v[idx]=a[num];
	}
	cout<<v.size();
	return 0;
}
