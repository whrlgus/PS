#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int N,K,words[50],ans;

void dfs(int k, int j, int word) {
	if (k==K) {
		int tmp=0;
		f(i,0,N)if((words[i]|word)==word)++tmp;
		if(ans<tmp)ans=tmp;
		return;
	}
	f(i,j,26)if((word&(1<<i))==0)dfs(k+1,i+1,word|(1<<i));
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N>>K;
	f(i,0,N){
		char tmp[16];cin>>tmp;
		int j=0;
		while(tmp[j]){
			words[i]|=(1<<(tmp[j]-'a'));
			++j;
		}
	}
	
	int val=((1<<0)|(1<<2)|(1<<8)|(1<<13)|(1<<19));
	dfs(5, 0, val);
	cout<<ans;
	
	return 0;
}
