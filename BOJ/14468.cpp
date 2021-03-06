#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str;cin>>str;
	bool vis[26]{};
	int ans=0;
	f(i,0,52){
		int idx=str[i]-'A';
		if(vis[idx])continue;
		vis[idx]=true;
		int j=i+1,cnt[26]{};
		int tmp;
		while(idx!=(tmp=str[(j++)%52]-'A'))++cnt[tmp];
		f(j,idx,26)if(cnt[j]==1)++ans;
	}
	cout<<ans;
	return 0;
}
