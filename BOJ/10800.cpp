#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MAXN=2e5+1;
struct ball{int color,size;}a[MAXN];
int S[MAXN],pre[MAXN];
vector<int> size[MAXN],sizePre[MAXN];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	f(i,0,n){
		int c,s;cin>>c>>s;
		a[i]={c,s};
		S[i]=s;
		size[c].push_back(s);
	}
	sort(S,S+n);
	f(i,0,n)pre[i+1]=pre[i]+S[i];
	
	f(i,0,MAXN)if(size[i].size()){
		sort(size[i].begin(),size[i].end());
		sizePre[i].push_back(0);
		f(j,0,size[i].size())sizePre[i].push_back(sizePre[i][j]+size[i][j]);
	}
	
	f(i,0,n){
		int ans=pre[upper_bound(S, S+n, a[i].size-1)-S];
		auto &ref=size[a[i].color];
		ans-=sizePre[a[i].color][upper_bound(ref.begin(), ref.end(), a[i].size-1)-ref.begin()];
		cout<<ans<<'\n';
	}
	return 0;
}




