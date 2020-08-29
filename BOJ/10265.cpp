#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int MAXN=1001;
int n,k,p[MAXN],mn,mx,chk[MAXN];
bool s[2][MAXN];
vector<int> rev[MAXN];

int findExtra(int u){
	chk[u]=-1;
	int ret=1;
	for(int v:rev[u])if(chk[v]!=-1)ret+=findExtra(v);
	return ret;
}

void findGroup(int u,int cnt){
	chk[u]=cnt;
	if(chk[p[u]]){
		mn=cnt-chk[p[u]]+1;
		mx=findExtra(u);
	}else findGroup(p[u],cnt+1);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	f(i,1,n){
		int tmp;cin>>tmp;
		p[i]=tmp;
		rev[tmp].push_back(i);
	}
	
	int idx=0;
	s[0][0]=s[1][0]=true;
	f(i,1,n)if(!chk[i]){
		int nIdx=idx^1;
		findGroup(i,1);
		f(j,mn,mx){
			int cnt=k-j;
			while(cnt>=0){
				if(s[idx][cnt])s[nIdx][cnt+j]=true;
				--cnt;
			}
		}
		f(i,0,k)s[nIdx][i]|=s[idx][i];
		idx=nIdx;
	}
	
	while(!s[idx][k])--k;
	cout<<k;
	
	return 0;
}
