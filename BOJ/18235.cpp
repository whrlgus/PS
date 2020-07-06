#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;
const int MAXN=5e5+1;
int n,a,b,s[2][MAXN],dk[]={1,-1};

int sol(){
	queue<int> q[2];
	q[0].push(a);
	q[1].push(b);
	int y=1,dx=1;
	while(!q[0].empty()&&!q[1].empty()){
		f(i,0,1){
			int size=q[i].size();
			while(size--){
				int x=q[i].front();q[i].pop();
				f(k,0,1){
					int nx=x+dx*dk[k];
					if(nx<=0||nx>n||s[i][nx]+1<y)continue;
					s[i][nx]=y;
					if(i==1&&s[0][nx]==y)return y;
					q[i].push(nx);
				}
			}
		}
		++y;
		dx<<=1;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>a>>b;
	f(i,1,n)s[0][i]=s[1][i]=MAXN;
	cout<<sol();
	return 0;
}
