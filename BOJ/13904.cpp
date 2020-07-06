#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n;
bool used[1000];
struct assignment{
	int d,w;
}a[1000];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n)cin>>a[i].d>>a[i].w;
	
	int i=a[0].d,ans=0;
	while(i){
		int k=-1,val=0;
		f(j,0,n)if(!used[j]&&i<=a[j].d&&val<a[j].w){
			val=a[j].w;
			k=j;
		}
		ans+=val;
		used[k]=true;
		--i;
	}
	cout<<ans;
	
	return 0;
}
