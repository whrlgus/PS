#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int n,m,cnt,tmp,ans,no[51][52];
bool updated,aware[51];

bool canLie(int party){
	int i=0;
	while(no[party][++i])if(aware[no[party][i]])return false;
	return true;
}

void update(int party){
	int i=0;
	while(no[party][++i])aware[no[party][i]]=true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>m>>cnt;
	while(cnt--){
		cin>>tmp;
		aware[tmp]=true;
	}
	f(i,1,m){
		cin>>cnt;
		f(j,1,cnt)cin>>no[i][j];
	}
	
	f(i,1,m){
		updated=false;
		f(j,1,m)if(!canLie(j)){
			update(j);
			updated=true;
		}
		if(!updated)break;
	}
	
	f(i,1,m)if(canLie(i))++ans;
	cout<<ans;
	
	return 0;
}

