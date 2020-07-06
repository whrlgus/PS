#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(char *str){
	char *l=str,*r=str;
	while(*r)++r;
	while(l<r)if(*l++!=*--r)return false;
	return true;
}

int main(){
	char str[101];cin>>str;
	cout<<(isPalindrome(str)?1:0);
	return 0;
}
