#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

typedef pair<int,int> pii;
const int MXN=1e5+1;

bool chk[MXN];
int s[3][MXN],n,p[3];
vector<pii> v[MXN];

void foo(int i){
    memset(chk,0,sizeof(chk));
    priority_queue<pii> pq;
    pq.push({0,p[i]});
    s[i][p[i]]=0;
    
    int j=n-1;
    while(1){
        pii tmp=pq.top();
        pq.pop();
        
        if(chk[tmp.second])continue;
        chk[tmp.second]=1;
        
        for(pii &ele:v[tmp.second]){
            int nd=ele.second-tmp.first;
            if(s[i][ele.first]<=nd)continue;
            s[i][ele.first]=nd;
            pq.push({-nd,ele.first});
        }
        if(!(--j))break;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>n;
    f(i,0,2)cin>>p[i];
    int m;cin>>m;
    f(i,1,m){
        int d,e,l;cin>>d>>e>>l;
        v[d].push_back({e,l});
        v[e].push_back({d,l});
    }
    
    memset(s,(1<<7)-1,sizeof(s));
    f(i,0,2)foo(i);
    
    int mx=-1,ans;
    f(i,1,n){
        int mn=1e9;
        f(j,0,2)mn=min(mn,s[j][i]);
        if(mx<mn){
            mx=mn;
            ans=i;
        }
    }
    cout<<ans;
    
    return 0;
}
