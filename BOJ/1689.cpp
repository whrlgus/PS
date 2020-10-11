#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MXN=1e6;
int n;
struct line{
	int a,b;
	bool operator< (const line& oth)const{
		return a<oth.a;
	}
} s[MXN];
priority_queue<int>	pq;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n)cin>>s[i].a>>s[i].b;
	sort(s,s+n);
	
	int ans=0;
	f(i,0,n){
		while(!pq.empty()&&-pq.top()<=s[i].a)pq.pop();
		ans=max(ans,(int)pq.size());
		pq.push(-s[i].b);
	}
	cout<<ans+1;
	return 0;
}
