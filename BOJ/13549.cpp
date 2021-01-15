#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MXN=1e5+1;
bool vis[MXN];
int n,k;
queue<int> a,b;


void push(queue<int> &q, int val){
	q.push(val);
	vis[val]=true;
}

void teleport(){
	while(!b.empty()){
		int tmp=b.front();b.pop();
		a.push(tmp);
		if(tmp)while((tmp<<=1)<MXN)if(!vis[tmp])push(a,tmp);
	}
}

int sol(){
	if(n>=k)return n-k;
	
	b.push(n);
	vis[n]=true;
	int ans=0;
	while(!b.empty()){
		teleport();
		int size=a.size();
		while(size--){
			int tmp=a.front();a.pop();
			if(tmp==k)return ans;
			if(!vis[tmp+1])push(b,tmp+1);
			if(tmp&&!vis[tmp-1])push(b,tmp-1);
		}
		++ans;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	cout<<sol();
	return 0;
}
