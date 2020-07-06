#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int MAXN=3e5+1;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,s;cin>>n>>s;
	
	vector<pair<int,int>> a;
	a.push_back({0,0});
	f(i,1,n){
		int h,c;cin>>h>>c;
		a.push_back({h,c});
	}
	sort(a.begin(),a.end());
	
	int m[MAXN],r=n,l=n-1;
	while(r>0){
		if(a[l].first+s<=a[r].first)m[r--]=l;
		else --l;
	}
	
	int p[MAXN][2]{};
	f(i,1,n){
		p[i][0]=max(p[i-1][0],p[i-1][1]);
		p[i][1]=max(p[m[i]][0],p[m[i]][1])+a[i].second;
	}
	cout<<max(p[n][0],p[n][1]);
	return 0;
}

