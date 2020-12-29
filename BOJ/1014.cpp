#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int n,m,s[11][1024],bitCount[1024];
vector<int> v;
char p[11][11]={".........."};

bool isValid(int x){
	int a=x&1;
	f(i,1,m-1){
		int b=x>>i&1;
		if(a&b)return false;
		a=b;
	}
	return true;
}

bool isPossible(int i,int x){
	f(j,0,m-1)if(p[i][j]!='.'&&((x>>j)&1))return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f(i,1,1023)bitCount[i]=bitCount[i>>1]+(i&1);
	
	int c;cin>>c;
	while(c--){
		cin>>n>>m;
		f(i,1,n)cin>>p[i];
		memset(s,0,sizeof(s));
		int size=(1<<m)-1;
		v.clear();
		f(i,0,size)if(isValid(i))v.push_back(i);
		
		int mx;
		f(i,1,n)for(int a:v)if(isPossible(i,a)){
			mx=0;
			for(int b:v)if(isValid(a|b))mx=max(mx,s[i-1][b]);
			s[i][a]=mx+bitCount[a];
		}
		mx=0;
		for(int a:v)mx=max(mx,s[n][a]);
		cout<<mx<<'\n';
	}
	return 0;
}
