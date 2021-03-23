#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

char b[10];
int di[]={1,0,1,1},dj[]={0,1,1,-1};

bool allEqual(char c,int i,int d){
	if(b[i]!=c)return false;
	f(j,1,3)if(b[i]!=b[i+3*j*di[d]+j*dj[d]])return false;
	return true;
}

bool hasLine(char c){
	f(j,0,2)f(i,0,3)if(allEqual(c,i*(j?3:1),j))return true;
	if(allEqual(c,0,2)||allEqual(c,2,3))return true;
	return false;
}

bool sol(){
	int cnt=0;
	bool full=true;
	f(i,0,9){
		if(b[i]=='X')++cnt;
		else if(b[i]=='O')--cnt;
		else full=false;
	}
	if(cnt<0||cnt>1||hasLine(cnt?'O':'X'))return false;
	
	char c=cnt?'X':'O';
	bool exist=hasLine(c),k=true;
	f(i,0,9)if(b[i]==c){
		b[i]='.';
		k&=hasLine(c);
		b[i]=c;
	}
	return exist?!k:full;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while(cin>>b&&b[0]!='e')cout<<(sol()?"valid":"invalid")<<'\n';
	return 0;
}
