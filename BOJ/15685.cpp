#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
#define fr(i,l,r) for(int i=l;i>=r;--i)
using namespace std;

int dx[]={1,0,-1,0},dy[]={0,-1,0,1},dd[]={1,2,3,0};
bool a[101][101];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	while(n--){
		int x,y,d,g;cin>>x>>y>>d>>g;
		a[x][y]=true;
		x+=dx[d];y+=dy[d];
		a[x][y]=true;
		vector<int>dirs={d};
		while(g--){
			fr(i,dirs.size()-1,0){
				int nd=dd[dirs[i]];
				a[x][y]=true;
				x+=dx[nd];y+=dy[nd];
				a[x][y]=true;
				dirs.push_back(nd);
			}
		}
	}
	
	int ans=0;
	f(i,0,100)f(j,0,100)if(a[i][j]&&a[i][j+1]&&a[i+1][j]&&a[i+1][j+1])++ans;
	cout<<ans;
	
	return 0;
}
