#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll k;cin>>k;
    ll val=1;
    while(val<=k)val<<=1;
    
    int cnt=0;
    while(k>1){
        val>>=1;
        if(k>val)k-=val,++cnt;
    }
    
    cout<<(cnt&1);
    return 0;
}


