#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

typedef long long ll;
int N,M,offset=1;
ll A[1<<21];

void update(int i,int k){
	i+=offset;
	A[i]=k;
	while(i>>=1){
		int j=i<<1;
		A[i]=A[j]+A[j+1];
	}
}

ll query(int i,int j){
	if(i>j)swap(i,j);
	i+=offset;
	j+=offset;
	ll sum=0;
	while(i!=j){
		if(i&1)sum+=A[i-1];
		if(!(j&1))sum+=A[j+1];
		i>>=1;
		j>>=1;
	}
	return A[i]-sum;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N>>M;
	while(offset<N)offset<<=1;
	--offset;
	while(M--){
		int a,b,c;cin>>a>>b>>c;
		if(a)update(b,c);
		else cout<<query(b,c)<<'\n';
	}
	
	return 0;
}
