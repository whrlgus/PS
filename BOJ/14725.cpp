#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

struct food{
	map<string,food> m;
}root;

void dfs(food *f,int depth){
	for(auto &tmp:f->m){
		cout<<string(depth<<1,'-')<<tmp.first<<'\n';
		dfs(&tmp.second,depth+1);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	food *tmp;
	while(n--){
		tmp=&root;
		int k;cin>>k;
		while(k--){
			string name;cin>>name;
			if(tmp->m.find(name)==tmp->m.end()){
				tmp->m[name]=food();
			}
			tmp=&tmp->m[name];
		}
	}
	dfs(&root,0);
	return 0;
}
