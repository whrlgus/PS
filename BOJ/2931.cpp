#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const string s="+|-1234.";
int R,C;
char b[25][26];
bool vis[25][25];
map<char,int> m;
map<int,vector<int>> di,dj;

void init(){
	for(char c:s)m[c]=m.size();
	
	di[0]={0,0,-1,1};
	dj[0]={-1,1,0,0};
	
	di[1]={-1,1};
	dj[1]={0,0};
	
	di[2]={0,0};
	dj[2]={-1,1};
	
	di[3]={0,1};
	dj[3]={1,0};
	
	di[4]={-1,0};
	dj[4]={0,1};
	
	di[5]={0,-1};
	dj[5]={-1,0};
	
	di[6]={0,1};
	dj[6]={-1,0};
}

bool possible(int i,int j){
	return i<0||j<0||i>=R||j>=C||b[i][j]=='.'?false:true;
}

bool match(int si,int sj,int ei,int ej){
	char c=b[si][sj];
	if(c=='Z')return true;
	if(c=='M')return false;
	
	int k=m[c];
	f(d,0,di[k].size())if(ei==si+di[k][d]&&ej==sj+dj[k][d])return true;
	return false;
}

bool check(int i,int j,int k){
	f(d,0,di[k].size()){
		int ni=i+di[k][d],nj=j+dj[k][d];
		if(!possible(ni,nj)||!match(ni,nj,i,j))return false;
	}
	return true;
}

void visit(int i,int j){
	vis[i][j]=true;
	if(b[i][j]=='Z')return;
	int k=m[b[i][j]];
	if(k==7)f(t,0,7)if(check(i,j,t)){
		cout<<i+1<<' '<<j+1<<' '<<s[t];
		exit(0);
	}
	
	f(d,0,di[k].size()){
		int ni=i+di[k][d],nj=j+dj[k][d];
		if(!vis[ni][nj])visit(ni,nj);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	init();
	cin>>R>>C;
	f(i,0,R)cin>>b[i];
	
	f(i,0,R)f(j,0,C)if(b[i][j]=='M'){
		vis[i][j]=true;
		f(d,0,4){
			int ni=i+di[0][d],nj=j+dj[0][d];
			if(possible(ni,nj))visit(ni,nj);
		}
	}
	
	return 0;
}
