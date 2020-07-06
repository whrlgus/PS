#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int getLength(int n,string &s){
	int until=s.length()/n, len=s.length()%n,i=0;
	while(i<until){
		string tmp=s.substr(i*n,n);
		int j=i+1;
		while(j<until&&tmp==s.substr(j*n,n))++j;
		int cnt=j-i;
		len+=n+(cnt>1?to_string(cnt).length():0);
		i=j;
	}
	return len;
}

int solution(string s) {
	int until=(s.length()>>1)+1, answer = s.length();
	f(i,1,until)answer=min(answer,getLength(i, s));
	return answer;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<string> s({"aabbaccc","ababcdcdababcdcd","abcabcdede","abcabcabcabcdededededede","xababcdcdababcdcd"});
	vector<int> result({7,9,8,14,17});
	f(i,0,s.size())cout<<(solution(s[i])==result[i])<<'\n';
	return 0;
}
