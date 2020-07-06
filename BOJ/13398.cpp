#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,s[2][2],num,idx=0,ans;
	cin>>n>>s[idx][0];
	ans=s[idx][0];
	s[idx][1]=-1000;
	while(--n){
		idx^=1;
		cin>>num;
		s[idx][0]=num+max(s[idx^1][0],0);
		s[idx][1]=max(s[idx^1][0],s[idx^1][1]+num);
		ans=max(ans,max(s[idx][0],s[idx][1]));
	}
	cout<<ans;
	return 0;
}
