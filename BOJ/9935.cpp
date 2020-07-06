#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

string a,b;
char ans[1000001];
int cnt;

bool isEqual(){
	if(b.length()>cnt)return false;
	int j=cnt-1;
	for(int i=b.length()-1;i>=0;--i,--j)if(b[i]!=ans[j])return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>a>>b;
	for(char c:a){
		ans[cnt++]=c;
		if(isEqual())cnt-=b.length();
	}
	if(cnt){
		ans[cnt]=0;
		cout<<ans;
	}else cout<<"FRULA";
	return 0;
}
