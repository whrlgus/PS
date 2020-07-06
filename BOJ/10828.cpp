#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n,s[10000],top,num;
char cmd[6];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	while(n--){
		cin>>cmd;
		if(cmd[0]=='p'){
			if(cmd[1]=='u') cin>>num,s[top++]=num;
			else cout<<(top>0?s[--top]:-1)<<'\n';
		}
		else if(cmd[0]=='s') cout<<top<<'\n';
		else if(cmd[0]=='e') cout<<(top<1)<<'\n';
		else cout<<(top>0?s[top-1]:-1)<<'\n';
	}
	return 0;
}
