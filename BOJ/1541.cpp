#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

char str[51],*ptr;

int getNum(){
	int ret=0;
	while('0'<=*ptr&&*ptr<='9'){
		ret*=10;
		ret+=*ptr-'0';
		++ptr;
	}
	return ret;
}

int getSum(){
	int ret=getNum();
	while(*ptr&&*ptr!='-'){
		++ptr;
		ret+=getNum();
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>str;
	ptr=str;
	int ans=getSum();
	while(*ptr){
		++ptr;
		ans-=getSum();
	}
	cout<<ans;
	return 0;
}
