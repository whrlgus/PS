#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n,p[9];
string str;
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
	for(int i=1;i<n;i+=2){
		int idx=i>>1;
		while(!signs.empty()&&p[signs.top().first]>=p[idx])da();
		signs.push({idx,str[i]});
		nums.push(str[i+1]-'0');
	}
	while(!signs.empty())da();
	int ret=nums.top();nums.pop();
	return ret;
}

int ga(int i,int j){
	++i;
	if(i==n/2)return na();
	int ret=ga(i,0);
	if(!j){
		int tmp=p[i];
		p[i]=2;
		ret=max(ret,ga(i,1));
		p[i]=tmp;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>str;
	for(int i=1;i<n;i+=2)p[i>>1]=str[i]=='*';
	cout<<ga(-1,0);
	return 0;
}
