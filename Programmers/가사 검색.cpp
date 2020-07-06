#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
#define fr(i,l,r) for(int i=l;i>=r;--i)
using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
	map<string,int> m;
	for(string& s:queries)m[s]=0;
	
	for(string& s:words){
		string tmp=s;
		f(i,0,tmp.length()){
			tmp[i]='?';
			if(m.find(tmp)!=m.end())m[tmp]++;
		}
		tmp=s;
		fr(i,tmp.length()-1,1){
			tmp[i]='?';
			if(m.find(tmp)!=m.end())m[tmp]++;
		}
	}
	
	vector<int> answer;
	for(string& s:queries)answer.push_back(m[s]);
	return answer;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<int> answer=solution({"frodo", "front", "frost", "frozen", "frame", "kakao"}, {"fro??", "????o", "fr???", "fro???", "pro?","?????"});
	for(int a:answer)cout<<a<<' ';
	return 0;
}
