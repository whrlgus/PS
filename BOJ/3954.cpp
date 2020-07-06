#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;
const int MAXM=1e5,LIMIT=5e7;

void fill(int nextPos[],string code){
	stack<int> s;
	f(i,0,code.length()){
		if(code[i]=='[')s.push(i);
		else if(code[i]==']'){
			nextPos[i]=s.top();
			nextPos[s.top()]=i;
			s.pop();
		}
	}
}

void sol(){
	unsigned char arr[MAXM]{};
	bool vis[MAXM]{};
	int nextPos[MAXM],ptr=0,idx=0,turns=LIMIT,sm,sc,si;
	string code,input;
	
	cin>>sm>>sc>>si;
	cin>>code;
	cin>>input;
	
	fill(nextPos,code);
	f(i,0,sc){
		char c=code[i];
		--turns;
		if(turns<0)vis[i]=true;
		if(turns==-LIMIT){
			f(j,0,sc)if(vis[j]){
				cout<<"Loops "<<j<<" "<<nextPos[j]<<"\n";
				return;
			}
		}
		if(c=='-')--arr[ptr];
		else if(c=='+')++arr[ptr];
		else if(c=='<')ptr=(ptr==0?sm-1:ptr-1);
		else if(c=='>')ptr=(ptr==sm-1?0:ptr+1);
		else if(c=='['){
			if(arr[ptr]==0)i=nextPos[i]-1;
		}else if(c==']'){
			if(arr[ptr]!=0)i=nextPos[i]-1;
		}else if(c==',')arr[ptr]=(idx==si?255:input[idx++]);
	}
	cout<<"Terminates\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;cin>>t;
	while(t--)sol();
	return 0;
}
