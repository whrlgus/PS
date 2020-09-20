#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int MX=3e5+1;
int n,cnt[MX],d,g;
pair<int,int> edge[MX];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,2,n){
		int a,b;cin>>a>>b;
		edge[i]={a,b};
		++cnt[a];
		++cnt[b];
	}
	
	f(i,1,n)if(cnt[i]>1)g+=cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
	f(i,2,n)d+=(cnt[edge[i].first]-1)*(cnt[edge[i].second]-1);
	
	int tmp=d-g*3;
	if(tmp>0)cout<<"D";
	else if(tmp<0)cout<<"G";
	else cout<<"DUDUDUNGA";
	return 0;
}
