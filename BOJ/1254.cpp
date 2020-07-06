#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

char str[1001];

bool isPalindrome(int l, int r){
	while(l<r)if(str[l++]!=str[r--])return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>str;
	int len=strlen(str)-1;
	f(i,0,len)if(isPalindrome(i, len)){
		cout<<len+i+1;
		break;
	}
	return 0;
}
