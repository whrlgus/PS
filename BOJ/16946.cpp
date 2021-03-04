#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int N=1e6;
int n,m,r,p[N],cnt[N],di[]={0,0,-1,1},dj[]={-1,1,0,0};
bool vis[1000][1000];
char b[1000][1001];

bool poss(int i,int j){
	return i>=0&&j>=0&&i<n&&j<m&&b[i][j]=='0';
}

void visit(int i,int j){
	vis[i][j]=true;
	p[i*m+j]=r;
	++cnt[r];
	f(d,0,4){
		int ni=i+di[d],nj=j+dj[d];
		if(poss(ni,nj)&&!vis[ni][nj])visit(ni,nj);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	f(i,0,n)cin>>b[i];
	
	f(i,0,n)f(j,0,m)if(b[i][j]=='0'&&!vis[i][j]){
		r=i*m+j;
		visit(i,j);
	}
	
	f(i,0,n){
		char str[1001]={};
		f(j,0,m){
			if(b[i][j]=='0')str[j]='0';
			else{
				int sum=1;
				map<int,int> ma;
				f(d,0,4){
					int ni=i+di[d],nj=j+dj[d],tmp=p[ni*m+nj];
					if(!poss(ni,nj)||ma[tmp])continue;
					ma[tmp]=1;
					sum+=cnt[tmp];
				}
				str[j]='0'+(sum)%10;
			}
		}
		cout<<str<<'\n';
	}
	
	return 0;
}
