#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

map<string,int> m;

struct node{
	node *next[26]{};
}root;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	while(n--){
		string s;cin>>s;
		if(++m[s]>1)cout<<s<<m[s];
		else{
			node *tmp=&root;
			int i=-1;
			while(++i<s.length()){
				cout<<s[i];
				if(!tmp->next[s[i]-'a'])break;
				tmp=tmp->next[s[i]-'a'];
			}
			while(i<s.length()){
				tmp->next[s[i]-'a']=new node();
				tmp=tmp->next[s[i]-'a'];
				++i;
			}
		}
		cout<<'\n';
		
	}
	return 0;
}
