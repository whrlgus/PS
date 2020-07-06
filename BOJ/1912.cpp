#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,ans,prev,curr;
	cin>>n>>ans;
	prev=ans;
	while(--n){
		int num;cin>>num;
		curr=num+max(prev,0);
		prev=curr;
		ans=max(ans,curr);
	}
	cout<<ans;
	return 0;
}
