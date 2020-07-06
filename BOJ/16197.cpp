#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n,m,di[]={0,0,1,-1},dj[]={1,-1,0,0};
bool s[20][20][20][20];
char p[20][21];
struct coin{
	int i,j;
	bool operator<(const coin &oth){return i==oth.i?j<oth.j:i<oth.i;}
	bool operator==(const coin &oth){return i==oth.i&&j==oth.j;}
};
queue<pair<coin,coin>> q;

bool isInBoundary(coin &x){
	return x.i>=0&&x.j>=0&&x.i<n&&x.j<m;
}

coin nextPos(coin x, int d){
	x.i+=di[d];
	x.j+=dj[d];
	if(!isInBoundary(x)||p[x.i][x.j]!='#')return x;
	return {x.i-di[d],x.j-dj[d]};
}

int sol(){
	int cnt=1;
	while(!q.empty()&&cnt<11){
		int size=q.size();
		while(size--){
			coin a=q.front().first,b=q.front().second;q.pop();
			f(d,0,4){
				coin na=nextPos(a, d),nb=nextPos(b, d);
				bool k=isInBoundary(na),l=isInBoundary(nb);
				
				if(k^l)return cnt;
				if(!(k&&l)||na==nb)continue;
				
				if(nb<na)swap(na, nb);
				bool &ref=s[na.i][na.j][nb.i][nb.j];
				if(!ref){
					q.push(make_pair(na, nb));
					ref=true;
				}
			}
		}
		++cnt;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	vector<coin> tmp;
	f(i,0,n){
		cin>>p[i];
		f(j,0,m)if(p[i][j]=='o'){
			tmp.push_back({i,j});
			p[i][j]='.';
		}
	}
	q.push(make_pair(tmp[0], tmp[1]));
	s[tmp[0].i][tmp[0].j][tmp[1].i][tmp[1].j]=true;
	cout<<sol();
	return 0;
}


