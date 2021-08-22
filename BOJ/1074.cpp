#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N,r,c;cin>>N>>r>>c;
    ++r,++c;
    
    int val=1<<N,ans=0;
    while(r!=1||c!=1){
        int tmp=val*val;
        if(r>val){
            r-=val;
            ans+=tmp<<1;
        }
        if(c>val){
            c-=val;
            ans+=tmp;
        }
        val>>=1;
    }
    cout<<ans;
    
    return 0;
}
