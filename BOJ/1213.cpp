#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
#define fr(i,l,r) for(int i=l;i>=r;--i)
using namespace std;

int cnt[26];
char mid;

bool hasAns(){
	f(i,0,26)if(cnt[i]&1){
		if(mid)return false;
		mid='A'+i;
		--cnt[i];
	}
	return true;
}

void printAns(){
	f(i,0,26)if(cnt[i]){
		int tmp=cnt[i]/2-1;
		cnt[i]-=(tmp+1);
		fr(j,tmp,0)cout<<(char)('A'+i);
	}
	if(mid)cout<<mid;
	fr(i,25,0)f(j,0,cnt[i])cout<<(char)('A'+i);
}

int main(){
	char c[51];cin>>c;
	fr(i,strlen(c)-1,0)++cnt[c[i]-'A'];
	if(!hasAns())cout<<"I'm Sorry Hansoo";
	else printAns();
	return 0;
}
