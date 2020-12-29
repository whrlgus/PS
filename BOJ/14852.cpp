#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MOD=1e9+7;
int n,s[2][5],idx;

int sol(){
	if(n--==1)return 2;
	s[0][0]=s[0][4]=2;
	s[0][1]=s[0][2]=s[0][3]=1;
	int total=7,prev;
	while(--n){
		prev=idx;
		idx^=1;
		s[idx][0]=s[idx][4]=total;
		s[idx][1]=s[prev][4];
		s[idx][2]=(s[prev][3]+s[prev][4])%MOD;
		s[idx][3]=(s[prev][2]+s[prev][4])%MOD;
		total=0;
		f(i,0,5)total=(total+s[idx][i])%MOD;
	}
	return total;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	cout<<sol();
	return 0;
}
