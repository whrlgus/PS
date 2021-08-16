#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
#define fr(i,l,r) for(int i=l;i>=r;--i)
using namespace std;
int M,N,L[(int)1e6];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>M>>N;
    f(i,0,N)cin>>L[i];
    
    int l=1,r=1e9;
    while(l<=r){
        int m=(l+r)>>1,cnt=0;
        fr(i,N-1,0)if((cnt+=L[i]/m)>=M)break;
        if(cnt>=M)l=m+1;
        else r=m-1;
    }
    cout<<l-1;
    
    return 0;
}

