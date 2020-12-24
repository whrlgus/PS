#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n,s[(int)1e6+1],tmp;
queue<int> q;

void insert(int x) {
	if(s[x])return;
	s[x]=tmp;
	q.push(x);
}

int sol(){
	q.push(n);
	int cnt=0;
	while(1){
		int size=q.size();
		while(size--){
			tmp=q.front();q.pop();
			if(tmp==1)
				return cnt;
			insert(tmp-1);
			if(tmp%2==0)insert(tmp/2);
			if(tmp%3==0)insert(tmp/3);
		}
		++cnt;
	}
	
	return -1;
}

void show(int x){
	if(x!=n)show(s[x]);
	cout<<x<<' ';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	cout<<sol()<<'\n';
	show(1);
	return 0;
}
