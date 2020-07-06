#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+1;
unsigned int s[MAXN];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(s,-1,sizeof(s));
	s[0]=0;
	int n;cin>>n;
	for(int i=0;i<=n;++i)
		for(int j=1,tmp;(tmp=j*j+i)<=n;++j)
			s[tmp]=min(s[tmp],1+s[i]);
	cout<<s[n];
	return 0;
}
