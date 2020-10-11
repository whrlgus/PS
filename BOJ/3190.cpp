#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;
int n,k,x,l,i=1,j=1,d,di[]={0,0,1,-1},dj[]={1,-1,0,0},L[]={3,2,0,1},R[]={2,3,1,0};
pair<int,int> lead[101][101],tail={1,1};
bool apple[101][101],chk[101][101];
char change[10001],c;

bool isOut(int i,int j){
	return i>n||j>n||i<=0||j<=0||chk[i][j];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	f(i,0,k){
		int a,b;cin>>a>>b;
		apple[a][b]=1;
	}
	cin>>l;
	while(l--){
		cin>>x>>c;
		change[x]=c;
	}
	int t=0;
	chk[1][1]=true;
	while(true){
		if(change[t]){
			if(change[t]=='L')d=L[d];
			else if(change[t]=='D')d=R[d];
		}
		int ni=i+di[d],nj=j+dj[d];
		if(isOut(ni,nj)){
			cout<<t+1;
			break;
		}
		chk[i][j]=true;
		lead[i][j]={ni,nj};
		i=ni;
		j=nj;
		
		if(!apple[i][j]){
			chk[tail.first][tail.second]=false;
			tail=lead[tail.first][tail.second];
		}else {
			apple[i][j]=false;
		}
		
		++t;
	}
	
	return 0;
}
