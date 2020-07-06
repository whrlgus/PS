#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

struct page{
	int idx,score;
	vector<string> links;
	double matchingScore;
};
unordered_map<string,page> m;

void convertLowerCase(string &str){
	f(i,0,str.size())str[i]=tolower(str[i]);
}

string getUrl(string &html){
	static const string urlPrefix="<meta property=\"og:url\" content=\"";
	size_t idx=html.find(urlPrefix)+urlPrefix.length();
	return html.substr(idx,html.find("\"",idx)-idx);
}

int getScore(string &word, string html){
	convertLowerCase(html);
	int cnt=0;
	size_t idx=html.find(word);
	while(idx!=string::npos){
		char c=html[idx+word.length()];
		if(c<'a'||c>'z')++cnt;
		idx=html.find(word,idx+word.length()+1);
	}
	return cnt;
}

vector<string> getLinks(string &html){
	static const string linkPrefix="<a href=\"";
	vector<string> links;
	size_t idx=html.find(linkPrefix);
	while(idx!=string::npos){
		idx+=linkPrefix.length();
		links.push_back(html.substr(idx,html.find("\"",idx)-idx));
		idx=html.find(linkPrefix,idx);
	}
	return links;
}

int solution(string word, vector<string> pages) {
	convertLowerCase(word);
	f(i,0,pages.size()){
		string &html=pages[i];
		int score=getScore(word,html);
		m[getUrl(html)]={i,score,getLinks(html),(double)score};
	}

	for(auto &ele:m)for(auto &link:ele.second.links)if(m.find(link)!=m.end())
		m[link].matchingScore+=(double)ele.second.score/ele.second.links.size();
	
	int answer=20;
	double maxMatchingScore=0;
	for(auto &ele:m){
		if(maxMatchingScore<ele.second.matchingScore)
			answer=ele.second.idx,maxMatchingScore=ele.second.matchingScore;
		else if(maxMatchingScore==ele.second.matchingScore)
			answer=min(answer,ele.second.idx);
	}
    return answer;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout<<solution("blind", {"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"});
	return 0;
}
