#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
#define fr(i,l,r) for(int i=l;i>=r;--i)
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string ip;cin>>ip;
	vector<string> v;
	int i=0,mid=-1;
	while(i<ip.length()){
		if(ip[i]==':'){
			++i;
			if(ip[i]==':'){
				mid=v.size();
				++i;
			}
			continue;
		}
		int j=i;
		while(j<ip.length()&&ip[j]!=':')++j;
		v.push_back(ip.substr(i,j-i));
		i=j;
	}
	ip.clear();
	if(mid==0)fr(j,8-v.size(),1)ip.append("0000:");
	f(i,0,v.size()){
		fr(j,4-v[i].size(),1)ip.push_back('0');
		ip.append(v[i]+":");
		if(mid==i+1)fr(j,8-v.size(),1)ip.append("0000:");
	}
	ip.pop_back();
	cout<<ip;
	return 0;
}
