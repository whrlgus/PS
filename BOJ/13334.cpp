#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MAXN=1e5;
int n,d;
struct info{
	int s,e;
	bool operator<(const info& oth)const{
		return s>oth.s;
	}
}a[MAXN];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n){
		cin>>a[i].s>>a[i].e;
		if(a[i].s>a[i].e)swap(a[i].s,a[i].e);
	}
	cin>>d;
	sort(a,a+n);
	
	int ans=0;
	priority_queue<int> pq;
	f(i,0,n){
		int tmp=a[i].s+d;
		while(!pq.empty()&&pq.top()>tmp)pq.pop();
		if(a[i].e<=tmp)pq.push(a[i].e);
		ans=max(ans,(int)pq.size());
	}
	cout<<ans;
	
	return 0;
}
