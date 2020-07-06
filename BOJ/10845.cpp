#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n,q[10000],front,back,num;
char cmd[6];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	while(n--){
		cin>>cmd;
		if(cmd[0]=='p'){
			if(cmd[1]=='u') cin>>num,q[back++]=num;
			else cout<<(front!=back?q[front++]:-1)<<'\n';
		}
		else if(cmd[0]=='s') cout<<back-front<<'\n';
		else if(cmd[0]=='e') cout<<(front==back)<<'\n';
		else if(cmd[0]=='f') cout<<(front!=back?q[front]:-1)<<'\n';
		else cout<<(front!=back?q[back-1]:-1)<<'\n';
	}
	return 0;
}
