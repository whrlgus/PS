#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int N,M,cnt_culture[2],garden[50][50],tmp[50][50][2],culture[2][5],cnt_yellow,ans;
int di[]={1,-1,0,0},dj[]={0,0,1,-1};
bool used[10];
struct Pos{int i,j;};
Pos yellow[10];

int spread(){
	f(i,0,N)f(j,0,M)tmp[i][j][0]=garden[i][j];
	
	queue<Pos> q[2];
	f(i,0,2)f(j,0,cnt_culture[i]){
		Pos &ref=yellow[culture[i][j]];
		tmp[ref.i][ref.j][0]=i;
		tmp[ref.i][ref.j][1]=0;
		q[i].push(ref);
	}
	
	int cnt_flower=0,sec=1;
	while(!q[0].empty()&&!q[1].empty()){
		int size=q[0].size();
		while(size--){
			int i=q[0].front().i,j=q[0].front().j;q[0].pop();
			if(tmp[i][j][0]==2)continue;
			f(d,0,4){
				int ni=i+di[d],nj=j+dj[d];
				int &ref=tmp[ni][nj][0];
				if(ni<0||nj<0||ni>=N||nj>=M||ref!=-2)continue;
				ref=0;
				tmp[ni][nj][1]=sec;
				q[0].push({ni,nj});
			}
		}
		size=q[1].size();
		while(size--){
			int i=q[1].front().i,j=q[1].front().j;q[1].pop();
			f(d,0,4){
				int ni=i+di[d],nj=j+dj[d];
				int &ref=tmp[ni][nj][0];
				if(ni<0||nj<0||ni>=N||nj>=M)continue;
				if(ref==-2){
					ref=1;
					tmp[ni][nj][1]=sec;
					q[1].push({ni,nj});
				}else if(ref==0&&tmp[ni][nj][1]==sec){
					ref=2;
					++cnt_flower;
				}
			}
		}
		++sec;
	}
	return cnt_flower;
}

void sol(int op,int prev,int idx){
	if(idx<0){
		if(op)ans=max(ans,spread());
		else sol(1,0,cnt_culture[1]-1);
		return;
	}
	f(i,prev,cnt_yellow)if(!used[i]){
		used[i]=true;
		culture[op][idx]=i;
		sol(op,i+1,idx-1);
		used[i]=false;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N>>M>>cnt_culture[0]>>cnt_culture[1];
	f(i,0,N)f(j,0,M){
		cin>>garden[i][j];
		if(garden[i][j]==2)yellow[cnt_yellow++]={i,j};
		garden[i][j]=(garden[i][j]==0?-1:-2);
	}
	sol(0,0,cnt_culture[0]-1);
	cout<<ans;
	return 0;
}

