#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

char a[51][52],b[51][52];
int n,m,ans;

bool isEqual(){
	f(i,0,n)f(j,0,m)if(a[i][j]!=b[i][j])return false;
	return true;
}

void flip(int r, int c){
	f(i,r-3,r)f(j,c-3,c)a[i][j]=(a[i][j]=='0'?'1':'0');
	++ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	f(i,0,n)cin>>a[i];
	f(i,0,n)cin>>b[i];
	f(i,2,n)f(j,2,m)if(a[i-2][j-2]!=b[i-2][j-2])flip(i+1,j+1);
	cout<<(isEqual()?ans:-1);
	return 0;
}
