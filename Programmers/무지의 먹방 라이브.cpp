#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int solution(vector<int> food_times, long long k) {
	int l=0,r=1e8;
	while(l<=r){
		int mid=(l+r)/2;
		long long tmp=k;
		for(int time:food_times)tmp-=min(time,mid);
		tmp<0?(r=mid-1):(l=mid+1);
	}
	
	--l;
	for(int &time:food_times){
		int tmp=min(time,l);
		time-=tmp;
		k-=tmp;
	}
	
	f(i,0,food_times.size())if(food_times[i]){
		if(k==0)return i+1;
		--k;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout<<solution({3,1,2}, 5);
	return 0;
}
