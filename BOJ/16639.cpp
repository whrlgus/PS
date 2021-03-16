#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int N,n,p[9];
string str;
bool chk[9];
stack<int> nums;
stack<pair<int,char>> signs;

void da(){
	int b=nums.top();nums.pop();
	int a=nums.top();nums.pop();
	char c=signs.top().second;signs.pop();
	
	if(c=='+')a+=b;
	else if(c=='-')a-=b;
	else a*=b;
	
	nums.push(a);
}

int na(){
	nums.push(str[0]-'0');
	for(int i=1;i<N;i+=2){
		int idx=i/2;
		while(!signs.empty()&&p[signs.top().first]>p[idx])da();
		signs.push({idx,str[i]});
		nums.push(str[i+1]-'0');
	}
	while(!signs.empty())da();
	int ret=nums.top();nums.pop();
	return ret;
}

int ga(int i){
	if(i==n)return na();
	int ret=INT_MIN;
	f(j,0,n)if(!chk[j]){
		p[i]=j;
		chk[j]=true;
		ret=max(ret,ga(i+1));
		chk[j]=false;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N>>str;
	n=N/2;
	cout<<ga(0);
	return 0;
}
