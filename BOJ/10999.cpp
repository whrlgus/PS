#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

typedef long long ll;

const int MAXN=1<<20;
int N,M,K;
ll t[MAXN<<1],a[MAXN],p[MAXN<<1];

ll build(int i,int s,int e){
	if(s==e)return t[i]=a[s];
	int m=(s+e)>>1,a=i<<1,b=a|1;
	return t[i]=build(a,s,m)+build(b,m+1,e);
}

void propagate(int i,int s,int e){
	if(!p[i])return;
	t[i]+=(e-s+1)*p[i];
	if(s!=e){
		p[i<<1]+=p[i];
		p[i<<1|1]+=p[i];
	}
	p[i]=0;
}

void update(int i,int s,int e,int l,int r,ll val){
	propagate(i,s,e);
	if(e<l||r<s)return;
	
	if(l<=s&&e<=r){
		p[i]+=val;
		propagate(i,s,e);
		return;
	}
	int m=(s+e)>>1,a=i<<1,b=a|1;
	update(a,s,m,l,r,val);
	update(b,m+1,e,l,r,val);
	t[i]=t[a]+t[b];
}

ll query(int i,int s,int e,int l,int r){
	if(e<l||r<s)return 0;
	
	propagate(i,s,e);
	if(l<=s&&e<=r)return t[i];
	int m=(s+e)>>1,a=i<<1,b=a|1;
	return query(a,s,m,l,r)+query(b,m+1,e,l,r);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N>>M>>K;
	f(i,0,N)cin>>a[i];
	build(1,0,N-1);
	
	M+=K;
	while(M--){
		ll a,b,c;cin>>a>>b>>c;
		if(a==1){
			ll d;cin>>d;
			update(1,0,N-1,b-1,c-1,d);
		}else cout<<query(1,0,N-1,b-1,c-1)<<'\n';
	}
	return 0;
}
