#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MXN=1e6+1;
vector<int> edge[MXN];
int s[MXN][2];

int sol(int i,bool k,int p){
    int &ref=s[i][k];
    if(ref!=-1)return ref;
    
    int sum=k;
    if(!k){
        for(int j:edge[i])if(j!=p)sum+=sol(j,1,i);
    }else {
        for(int j:edge[i])if(j!=p)sum+=min(sol(j,0,i),sol(j,1,i));
    }
    return ref=sum;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;cin>>n;
    while(--n){
        int a,b;cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    memset(s,-1,sizeof(s));
    cout<<min(sol(1,0,0),sol(1,1,0));
    return 0;
}
