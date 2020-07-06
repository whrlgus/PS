#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;
int n,m,tmp,s[40][2]={{1,0}};
bool a[40];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	while(m--){
		cin>>tmp;
		a[tmp-1]=true;
	}
	f(i,1,n){
		s[i][0]=s[i-1][0]+s[i-1][1];
		s[i][1]=(a[i]||a[i-1]?0:s[i-1][0]);
	}
	cout<<s[n-1][0]+s[n-1][1];
	
	return 0;
}
