#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

typedef pair<int,int> pii;
int ans;
vector<pii> edge[10001];

int sol(int i){
    vector<int> sum;
    for(auto &ele:edge[i])sum.push_back(sol(ele.first)+ele.second);
    sort(sum.begin(),sum.end());
    int size=sum.size();
    if(size>1)ans=max(ans,sum[size-1]+sum[size-2]);
    return size==0?0:sum.back();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;cin>>n;
    f(i,1,n){
        int a,b,c;cin>>a>>b>>c;
        edge[a].push_back({b,c});
    }
    cout<<max(ans,sol(1));
    
    return 0;
}
