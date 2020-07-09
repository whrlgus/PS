#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int INF=2e6+2;
int n,s[20];
bool a[INF];

void dfs(int i,int sum){
	if(i==n){
		a[sum]=true;
		return;
	}
	dfs(i+1,sum);
	dfs(i+1,sum+s[i]);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n)cin>>s[i];
	dfs(0,0);
	f(i,1,INF)if(!a[i]){
		cout<<i;
		break;
	}
	return 0;
}
