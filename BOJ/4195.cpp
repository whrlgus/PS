#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int F=2e5+1;
int cnt[F],p[F],r[F];
unordered_map<string,int> m;

int root(int x){
	return p[x]<0?x:p[x]=root(p[x]);
}

void check(string s){
	if(m[s])return;
	int i=m.size();
	m[s]=i;
	p[i]=-1;
	cnt[i]=r[i]=1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;cin>>t;
	while(t--){
		m.clear();
		int f;cin>>f;
		while(f--){
			string a,b;cin>>a>>b;
			check(a);
			check(b);
			
			int ra=root(m[a]),rb=root(m[b]),c=cnt[ra];
			if(ra!=rb){
				if(r[ra]>r[rb]){
					p[rb]=ra;
					c=cnt[ra]+=cnt[rb];
				}else{
					p[ra]=rb;
					c=cnt[rb]+=cnt[ra];
					if(r[ra]==r[rb])++r[rb];
				}
			}
			cout<<c<<'\n';
		}
	}
	return 0;
}
