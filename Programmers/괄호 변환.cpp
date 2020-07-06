#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int getBoundary(string &p){
	int i=0,j=(p[0]=='('?1:-1);
	while(++i<p.length()&&j)j+=(p[i]=='('?1:-1);
	return i;
}

string reverse(string &p){
	string ret=p.substr(1,p.length()-2);
	for(char &c:ret)c=(c=='('?')':'(');
	return ret;
}

bool isCorrect(string &p){
	int i=0,j=(p[0]=='('?1:-1);
	while(++i<p.length()){
		if(j<0)return false;
		j+=(p[i]=='('?1:-1);
	}
	return true;
}

string solution(string p) {
	if(p.length()==0)return p;
	int idx=getBoundary(p);
	string u=p.substr(0,idx),v=(idx==p.length()?"":solution(p.substr(idx)));
	return isCorrect(u)?u+v:'('+v+')'+reverse(u);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout<<solution("(()())()");
	return 0;
}
