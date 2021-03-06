#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int c,n,t[20000];
struct info{
	int a,b;
	bool operator <(const info &oth) const{
		return b>oth.b;
	}
}s[20000];

bool comp(info &x, info &y){
	return x.a<y.a;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>c>>n;
	f(i,0,c)cin>>t[i];
	f(i,0,n)cin>>s[i].a>>s[i].b;
	sort(t,t+c);
	sort(s,s+n,comp);
	
	priority_queue<info> q;
	int i=0,j=0,ans=0;

	while(i<c){
		while(!q.empty()&&q.top().b<t[i])q.pop();
		while(j<n&&s[j].a<=t[i]){
			if(t[i]<=s[j].b)q.push(s[j]);
			++j;
		}
		if(!q.empty())q.pop(),++ans;
		++i;
	}
	cout<<ans;
	return 0;
}
