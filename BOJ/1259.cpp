#include<bits/stdc++.h>
using namespace std;

int reverse(int a, int b){
	if(!a)return b;
	return reverse(a/10,b*10+a%10);
}

bool isPalindrome(int num){
	return num==reverse(num,0);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int num;
	while(cin>>num&&num)cout<<(isPalindrome(num)?"yes":"no")<<'\n';
	return 0;
}
