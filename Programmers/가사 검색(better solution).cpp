#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

bool comp(const string &a, const string &b){
	return a.length()==b.length()?a<b:a.length()<b.length();
}

string replace(string &s, char val){
	string ret=s;
	for(char &c:ret)if(c=='?')c=val;
	if(s[0]=='?')reverse(ret.begin(), ret.end());
	return ret;
}

vector<int> solution(vector<string> words, vector<string> queries){
	vector<string> words_r;
	for(string s:words){
		reverse(s.begin(), s.end());
		words_r.push_back(s);
	}
	sort(words.begin(),words.end(),comp);
	sort(words_r.begin(),words_r.end(),comp);
	
	vector<int> answer;
	for(string &s:queries){
		string a=replace(s,'a'),b=replace(s,'z');
		vector<string> &ref=(s[0]=='?'?words_r:words);
		answer.push_back(upper_bound(ref.begin(), ref.end(), b, comp)-lower_bound(ref.begin(), ref.end(), a, comp));
	}
	return answer;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution({"frodo", "front", "frost", "frozen", "frame", "kakao"}, {"fro??", "????o", "fr???", "fro???", "pro?"});
	return 0;
}
