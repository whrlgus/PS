#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;
int n,guiltIdx[16],r[16][16],eunjin,ans;
bool dead[16];
void process_day(int);
void process_night(int);

void process_night(int cnt){
	f(i,0,n)if(i!=eunjin&&!dead[i]){
		dead[i]=true;
		f(j,0,n)guiltIdx[j]+=r[i][j];
		process_day(cnt+1);
		f(j,0,n)guiltIdx[j]-=r[i][j];
		dead[i]=false;
	}
}

void process_day(int cnt){
	int mxIdx=0,no;
	f(i,0,n)if(!dead[i]&&mxIdx<guiltIdx[i])mxIdx=guiltIdx[i],no=i;
	
	if(no==eunjin) ans=max(ans,cnt);
	else{
		dead[no]=true;
		process_night(cnt);
		dead[no]=false;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n)cin>>guiltIdx[i];
	f(i,0,n)f(j,0,n)cin>>r[i][j];
	cin>>eunjin;
	
	n&1?process_day(0):process_night(0);
	cout<<ans;
	
	return 0;
}
