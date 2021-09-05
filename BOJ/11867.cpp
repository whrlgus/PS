#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;cin>>n>>m;
    cout<<((n*m)&1?'B':'A');
    return 0;
}
