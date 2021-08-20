#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

string a;

bool isPossible(int n){
    if(n==1)return true;
    int half=n>>1;
    --n;
    f(i,0,half)if(a[i]==a[n-i])return false;
    return isPossible(half);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>a;
        cout<<(isPossible(a.length())?"YES":"NO")<<'\n';
    }
    return 0;
}


