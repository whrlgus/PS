#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MAXN=1e4;
bool notPrime[MAXN],vis[MAXN];
int a,b;

void setPrimeNum(){
	f(i,2,100){
		if(notPrime[i])continue;
		int j=i*i;
		while(j<MAXN){
			notPrime[j]=true;
			j+=i;
		}
	}
}

void pushNext(queue<int> &q,int num){
	int div=1;
	f(i,0,4){
		int tmp=(num/div)%10;
		int tnum=num-tmp*div;
		f(j,i==3?1:0,10){
			int nnum=tnum+j*div;
			if(!vis[nnum]&&!notPrime[nnum]){
				q.push(nnum);
				vis[nnum]=true;
			}
		}
		div*=10;
	}
}

void sol(){
	memset(vis,0,sizeof(vis));
	cin>>a>>b;
	
	queue<int> q;
	vis[a]=true;
	q.push(a);
	int cnt=0;
	while(!q.empty()){
		int size=q.size();
		while(size--){
			int tmp=q.front();q.pop();
			if(b==tmp){
				cout<<cnt<<'\n';
				return;
			}
			pushNext(q,tmp);
		}
		++cnt;
	}
	
	cout<<"Impossible\n";
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	setPrimeNum();
	int t;cin>>t;
	while(t--)sol();
	return 0;
}
