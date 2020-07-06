#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MAXN=1003002;
bool p[MAXN]={true,true};

int reverse(int a, int b){
	if(!a)return b;
	return reverse(a/10,b*10+a%10);
}

bool isPalindrome(int num){
	return num==reverse(num,0);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f(i,2,MAXN)if(!p[i])for(int j=2*i;j<MAXN;j+=i)p[j]=true;
	int n;cin>>n;
	f(i,n,MAXN)if(!p[i]&&isPalindrome(i)){
		cout<<i;
		break;
	}
	return 0;
}
