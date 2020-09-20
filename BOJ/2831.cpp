#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

typedef vector<int> vi;
int n;
vi a,b,c,d;

void read(vi &e, vi &f){
	f(i,0,n){
		int tmp;cin>>tmp;
		if(tmp<0)e.push_back(-tmp);
		else f.push_back(tmp);
	}
	sort(e.begin(),e.end());
	sort(f.begin(),f.end());
}

int count(vi &e, vi &f){
	int j=0,cnt=0;
	f(i,0,e.size()){
		if(j==f.size())break;
		if(e[i]>f[j])++j,++cnt;		
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	read(a,b);
	read(c,d);
	cout<<count(a,d)+count(c,b);
	return 0;
}
