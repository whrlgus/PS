#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MX=3e5;
int n,k,bag[MX];
struct jewelry{
	int m,v;
	bool operator<(const jewelry &oth)const{
		return v<oth.v;
	}
} jew[MX];

bool comp(jewelry &a, jewelry &b){
	return a.m>b.m;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	f(i,0,n)cin>>jew[i].m>>jew[i].v;
	f(i,0,k)cin>>bag[i];
	sort(jew,jew+n,comp);
	sort(bag,bag+k);
		
	priority_queue<jewelry> q;
	long long ans=0;
	--n;
	f(i,0,k){
		while(n>=0&&bag[i]>=jew[n].m)q.push(jew[n--]);
		if(!q.empty()){
			ans+=q.top().v;
			q.pop();
		}
	}
	cout<<ans;
	return 0;
}
