#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

struct stone{int a,b,c;};
set<int> s;
queue<stone> q;

void sort(stone &tmp){
	if(tmp.a>tmp.b)swap(tmp.a,tmp.b);
	
	if(tmp.a>tmp.c){
		int t=tmp.c;
		tmp.c=tmp.b;
		tmp.b=tmp.a;
		tmp.a=t;
	}else if(tmp.b>tmp.c)swap(tmp.b,tmp.c);
}

int boo(stone &tmp){
	return tmp.a*1e6+tmp.b*1e3+tmp.c;
}

void foo(stone tmp){
	sort(tmp);
	int num=boo(tmp);
	if(s.find(num)!=s.end())return;
	s.insert(num);
	q.push(tmp);
}

int sol(){
	while(!q.empty()){
		stone tmp=q.front();q.pop();
		if(tmp.a==tmp.b&&tmp.b==tmp.c)return true;
		
		if(tmp.a<tmp.b)foo({tmp.a*2,tmp.b-tmp.a,tmp.c});
		if(tmp.b<tmp.c)foo({tmp.b*2,tmp.c-tmp.b,tmp.a});
		if(tmp.a<tmp.c)foo({tmp.a*2,tmp.c-tmp.a,tmp.b});
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	stone tmp;cin>>tmp.a>>tmp.b>>tmp.c;
	sort(tmp);
	s.insert(boo(tmp));
	q.push(tmp);
	cout<<sol();
	return 0;
}
