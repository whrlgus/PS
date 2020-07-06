#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MAXN=1e4;
int s[MAXN],cnt[6],idx,offset,n;

bool fill(int res1,int res2){
	int val,mnCnt=MAXN;
	f(k,1,6)if(k!=s[idx-1]&&k!=res1&&k!=res2&&mnCnt>cnt[k])val=k,mnCnt=cnt[k];
	s[idx++]=val;
	++cnt[val];
	return idx==MAXN;
}

void init(){
	s[idx++]=1;
	++cnt[1];
	while(true){
		++n;
		f(i,0,6){
			++offset;
			f(j,0,n){
				int tmp=idx-offset,res1=(!i&&!j?0:s[tmp]),res2=(j==n-1&&i<5?0:s[tmp+1]);
				if(fill(res1,res2))return;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	init();
	int c;cin>>c;
	while(c--){
		cin>>n;
		cout<<s[n-1]<<'\n';
	}
	return 0;
}
