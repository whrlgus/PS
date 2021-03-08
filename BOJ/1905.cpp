#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int Lx,Ly,N;
struct info{
	int p[5];
	bool operator<(const info& oth)const{
		return p[2]>oth.p[2];
	}
};
vector<info> v;

bool intersect(int i,int b[]){
	int *a=v[i].p;
	f(k,0,2){
		int l=k+3;
		bool t=a[l]<=b[l]&&b[l]<a[l]+a[k];
		bool s=b[l]<=a[l]&&a[l]<b[l]+b[k];
		if(!t&&!s)return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>Lx>>Ly>>N;
	int ans=0;
	f(i,0,N){
		info tmp;
		f(j,0,5)cin>>tmp.p[j];
		int mx=0;
		f(j,0,i)if(intersect(j,tmp.p)){
			mx=v[j].p[2];
			break;
		}
		ans=max(ans,tmp.p[2]+=mx);
		v.insert(lower_bound(v.begin(), v.end(), tmp), tmp);
	}
	cout<<ans;
	
	
	return 0;
}

