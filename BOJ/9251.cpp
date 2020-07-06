#include<bits/stdc++.h>
#define N 1001
using namespace std;

int i,j,s[N][N];
char a[N],b[N];

int main(){
	cin>>a>>b;
	for(i=0;a[i];++i)for(j=0;b[j];++j){
		if(a[i]==b[j])s[i+1][j+1]=s[i][j]+1;
		else s[i+1][j+1]=max(s[i][j+1],s[i+1][j]);
	}
	cout<<s[i][j];
	return 0;
}
