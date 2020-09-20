#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
#define fr(i,l,r) for(int i=l;i>=r;--i)
using namespace std;

int n,a[101][2];
bool s[50001];

int sol(){
	int sum=0,idx=0;
	f(i,1,n){
		cin>>a[i][0]>>a[i][1];
		sum+=a[i][0]*a[i][1];
	}
	if(sum%2)return 0;
	
	memset(s,0,sizeof(s));
	s[0]=true;
	int half=sum/2;
	f(i,1,n){
		fr(j,half,0)if(s[j])f(k,1,a[i][1]){
			int tmp=j+a[i][0]*k;
			if(tmp>half)break;
			if(s[tmp])break;
			s[tmp]=true;
		}
		if(s[half])return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while(cin>>n)cout<<sol()<<'\n';
	return 0;
}
