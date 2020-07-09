#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n,m,k,cnt,di[]={0,0,-1,1},dj[]={-1,1,0,0};
struct info{
	int x,y,s;
}a[10001];
char b[100][101];
bool chk[100][100];

bool isValid(int i,int j){
	return i>=0&&i<n&&j>=0&&j<m&&b[i][j]=='*';
}

int getSize(int i,int j){
	int size=50;
	f(d,0,4){
		int tmp=0,ni=i,nj=j;
		while(isValid(ni+=di[d],nj+=dj[d]))++tmp;
		size=min(size,tmp);
	}
	f(d,0,4){
		int ni=i,nj=j;
		f(i,0,size){
			ni+=di[d],nj+=dj[d];
			if(!chk[ni][nj])--cnt,chk[ni][nj]=true;
		}
	}
	return size;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	f(i,0,n){
		cin>>b[i];
		f(j,0,m)if(b[i][j]=='*')++cnt;
	}
	
	f(i,0,n)f(j,0,m)if(b[i][j]=='*'){
		int size=getSize(i,j);
		if(size){
			if(!chk[i][j])--cnt,chk[i][j]=true;
			a[k++]={i+1,j+1,size};
		}
	}
	
	if(cnt)cout<<-1;
	else{
		cout<<k<<'\n';
		f(i,0,k)cout<<a[i].x<<' '<<a[i].y<<' '<<a[i].s<<'\n';
	}
	return 0;
}
