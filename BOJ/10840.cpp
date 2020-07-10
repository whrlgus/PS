#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
#define fr(i,l,r) for(int i=l;i>=r;--i)
using namespace std;

string a,b;
set<vector<int>> s;

int main(){
	cin>>a>>b;
	f(i,0,a.length())a[i]-='a';
	f(i,0,b.length())b[i]-='a';

	int len=(int)min(a.length(),b.length());
	while(len){
		vector<int> v(26,0);
		f(i,0,len)++v[a[i]];
		s.insert(v);
		f(i,len,a.length()){
			--v[a[i-len]];
			++v[a[i]];
			s.insert(v);
		}

		vector<int>(26,0).swap(v);
		f(i,0,len)++v[b[i]];
		if(s.find(v)!=s.end())break;
		bool k=false;
		f(i,len,b.length()){
			--v[b[i-len]];
			++v[b[i]];
			if(s.find(v)!=s.end()){
				k=true;
				break;
			}
		}
		if(k)break;

		s.clear();
		--len;
	}
	cout<<len;
	
	return 0;
}
