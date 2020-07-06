#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int d,k,s[2][2]={{0,1},{1,0}},idx;

void print(){
	int i=0;
	while(++i){
		int tmp=k-i*s[idx][0];
		if(tmp%s[idx][1]==0&&i<=tmp/s[idx][1]){
			cout<<i<<'\n'<<tmp/s[idx][1];
			return;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>d>>k;
	--d;
	while(--d){
		idx^=1;
		s[idx][0]+=s[idx^1][0];
		s[idx][1]+=s[idx^1][1];
	}
	print();
	return 0;
}
