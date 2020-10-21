#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

stack<char> s;

void printTop(){
	cout<<s.top();
	s.pop();
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string infix; cin>>infix;
	for(char c:infix){
		if('A'<=c&&c<='Z'){
			cout<<c;
			continue;
		}
		if(c==')'){
			while(s.top()!='(')printTop();
			s.pop();
			continue;
		}
		if(c=='+'||c=='-')while(!s.empty()&&s.top()!='(')printTop();
		else if(c!='('&&!s.empty()&&(s.top()=='*'||s.top()=='/'))printTop();
		s.push(c);
	}
	while(!s.empty())printTop();
	return 0;
}

