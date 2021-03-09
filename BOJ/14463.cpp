#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MAXN=1<<17;
int N,t[MAXN];
pair<int,int> p[50000];

void update(int i,int val){
	while(i<MAXN){
		t[i]+=val;
		i+=(i&-i);
	}
}

int query(int i){
	int ret=0;
	while(i){
		ret+=t[i];
		i-=(i&-i);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N;
	N<<=1;
	memset(p,-1,sizeof(p));
	f(i,0,N){
		int j;cin>>j;--j;
		(p[j].first<0?p[j].first:p[j].second)=i;
	}
	N=N>>1;
	sort(p,p+N);
	
	int ans=0;
	f(i,0,N){
		ans+=(query(p[i].second)-query(p[i].first));
		update(p[i].second,1);
	}
	cout<<ans;
	
	return 0;
}
