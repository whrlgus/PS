#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int N,M,K,l,s[100][100][80],di[]={0,0,-1,1},dj[]={-1,1,0,0};
char B[100][101];
string word;

int sol(int i,int j,int k){
	int &ref=s[i][j][k];
	if(ref!=-1)return ref;
	ref=0;
	if(k==l)return ref=1;
	++k;
	f(d,0,4){
		int ni=i,nj=j;
		f(e,0,K){
			ni+=di[d];
			nj+=dj[d];
			if(ni<0||nj<0||ni>=N||nj>=M)break;
			if(B[ni][nj]==word[k])ref+=sol(ni,nj,k);
		}
	}
	return ref;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N>>M>>K;
	f(i,0,N)cin>>B[i];
	cin>>word;
	reverse(word.begin(),word.end());
	l=word.length()-1;
	memset(s,-1,sizeof(s));
	int ans=0;
	f(i,0,N)f(j,0,M)if(B[i][j]==word[0])ans+=sol(i,j,0);
	cout<<ans;
	
	return 0;
}

