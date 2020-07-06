#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;
int mxCnt;

bool isValid(int cnt, char *a, char *b){
	while(cnt--){
		if(*a=='2'&&*a==*b)return false;
		--a;
		--b;
	}
	return true;
}

void sol(char *a, char *b, int lenA, int lenB){
	f(i,0,lenA){
		int cnt=min(i+1,lenB);
		if(isValid(cnt, a+i, b))mxCnt=max(mxCnt,cnt);
	}
}

int main(){
	char a[101],b[101];cin>>a>>b;
	int lenA=strlen(a),lenB=strlen(b);
	sol(a,b+lenB-1,lenA,lenB);
	sol(b,a+lenA-1,lenB,lenA);
	cout<<lenA+lenB-mxCnt;
	return 0;
}
