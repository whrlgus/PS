#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const string YOLO="123456780";
unordered_set<string> s;
int di[]={0,0,1,-1},dj[]={1,-1,0,0};

pair<int,int> find(string p){
	f(i,0,3)f(j,0,3)if(p[3*i+j]=='0')return {i,j};
	return {-1,-1};
}

int sol(string p){
	queue<string> q;
	q.push(p);
	
	int ans=0;
	while(!q.empty()){
		int size=q.size();
		while(size--){
			string tmp=q.front();q.pop();
			if(s.find(tmp)!=s.end())continue;
			s.insert(tmp);
			if(tmp==YOLO)return ans;
			
			auto pos=find(tmp);
			int i=pos.first,j=pos.second;
			f(d,0,4){
				int ni=i+di[d],nj=j+dj[d];
				if(ni<0||nj<0||ni==3||nj==3)continue;
				string np=tmp;
				swap(np[3*i+j],np[3*ni+nj]);
				q.push(np);
			}
		}
		++ans;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string p="";
	f(i,0,3)f(j,0,3){
		int tmp;cin>>tmp;
		p+=('0'+tmp);
	}
	cout<<sol(p);
	return 0;
}
