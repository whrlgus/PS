#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
int nn;
ll t[1<<18];
pii p[1<<17];

bool comp(pii &a, pii &b){
	return a.second>b.second;
}

void update(ll i,ll val){
	while(i<=nn){
		t[i]+=val;
		i+=(i&-i);
	}
}

ll query(ll i){
	ll ret=0;
	while(i){
		ret+=t[i];
		i-=(i&-i);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	memset(p,-1,sizeof(p));
	nn=n<<1;
	f(i,0,nn){
		ll j;cin>>j;--j;
		(p[j].first<0?p[j].first:p[j].second)=(i<n?i:nn-i+n-1);
	}
	sort(p,p+n);
	ll mn=0;
	f(i,0,n){
		mn+=(query(p[i].second)-query(p[i].first));
		update(p[i].second,1);
	}
	
	ll pre=mn;
	for(int i=n-1;i>=0;--i){
		ll cur=pre+3*n-1-2*p[i].second;
		mn=min(mn,cur);
		pre=cur;
	}
	sort(p,p+n,comp);
	f(i,0,n){
		ll cur=pre+n-1-2*p[i].first;
		mn=min(mn,cur);
		pre=cur;
	}
	
	
	cout<<mn;
	return 0;
}
