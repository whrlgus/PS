#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int INF=5e6;
int n,m,a[6001][3],s[501];

bool update(){
	bool k=false;
	f(j,1,m)if(s[a[j][0]]!=INF){
		int tmp=s[a[j][0]]+a[j][2];
		if(s[a[j][1]]>tmp){
			k=true;
			if(tmp<-INF)continue;
			s[a[j][1]]=tmp;
		}
	}
	return k;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	f(i,1,m)cin>>a[i][0]>>a[i][1]>>a[i][2];
	
	f(i,2,n)s[i]=INF;
	f(i,2,n)if(!update())break;
	if(update())cout<<-1;
	else f(i,2,n)cout<<(s[i]==INF?-1:s[i])<<'\n';
	
	return 0;
}
