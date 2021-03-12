#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n,m,ans;
bool p[10];

bool possible(int num){
	if(!num)return !p[0];
	while(num){
		if(p[num%10])return false;
		num/=10;
	}
	return true;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	f(i,0,m){
		int tmp;cin>>tmp;
		p[tmp]=true;
	}
	
	ans=abs(n-100);
	if(m!=10){
		int i=n;
		while(i>=0&&!possible(i))--i;
		if(i!=-1)ans=min(ans,abs(i-n)+(int)(to_string(i).length()));
		i=n;
		while(++i<=1111111&&!possible(i));
		ans=min(ans,abs(i-n)+(int)(to_string(i).length()));
	}
	cout<<ans;
	
	return 0;
}

