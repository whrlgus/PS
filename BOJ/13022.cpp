#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

bool isValid(char **i){
	static char order[]="wolf";
	int cnt[4]{};
	f(j,0,4)while(**i==order[j])++*i,++cnt[j];
	return cnt[0]==cnt[1]&&cnt[1]==cnt[2]&&cnt[2]==cnt[3];
}

bool sol(){
	char word[51];cin>>word;
	char *i=word;
	while(*i)if(!isValid(&i))return 0;
	return 1;
}
int main(){
	cout<<sol();
	return 0;
}
