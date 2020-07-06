#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MAXR=3e4,MAXC=30;
int R,C,N,s[MAXC][MAXR],cnt[MAXC];
char B[MAXR+1][MAXC+1];

void update(int c){
	int val,i,j;
	while(cnt[c]){
		val=s[c][cnt[c]],i=val/C,j=val%C;
		if(B[i][j]=='.')break;
		--cnt[c];
	}
	
	val=s[c][cnt[c]],i=val/C,j=val%C;
	while(true){
		++i;
		if(B[i][j]=='X')break;
		if(B[i][j]=='O'){
			if(j>0&&B[i-1][j-1]=='.'&&B[i][j-1]=='.')--j;
			else if(B[i-1][j+1]=='.'&&B[i][j+1]=='.')++j;
			else break;
		}
		s[c][++cnt[c]]=i*C+j;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>R>>C;
	f(i,0,R)cin>>B[i];
	cin>>N;

	f(i,0,C)s[i][0]=i,B[R][i]='X';
	while(N--){
		int c;cin>>c;
		update(--c);
		int val=s[c][cnt[c]--];
		B[val/C][val%C]='O';
	}
	
	f(i,0,R)cout<<B[i]<<'\n';
	return 0;
}
