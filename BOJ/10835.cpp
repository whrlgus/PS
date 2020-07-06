#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int MAXN=2001;
int n,A[MAXN],B[MAXN],s[MAXN][MAXN],ans;


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(s,-1,sizeof(s));
	cin>>n;
	f(i,1,n)cin>>A[i];
	f(i,1,n)cin>>B[i];
	
	s[1][1]=0;
	f(i,2,n){
		if(A[1]>B[i-1])s[1][i]=s[1][i-1]+B[i-1];
		else break;
	}
	f(i,2,n){
		s[i][1]=s[i-1][1];
		f(j,2,n){
			s[i][j]=max(s[i-1][j-1],s[i-1][j]);
			if(s[i][j-1]!=-1&&A[i]>B[j-1])s[i][j]=max(s[i][j],s[i][j-1]+B[j-1]);
		}
	}
	
	f(i,1,n)ans=max(ans,s[n][i]);
	f(i,1,n)if(s[i][n]!=-1)ans=max(ans,s[i][n]+(A[i]>B[n]?B[n]:0));
	
	cout<<ans;
	return 0;
}
