#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;
const int MXN=1<<10;
int a[MXN][MXN];

int foo(int i, int j, int n){
    if(n==1)return a[i][j];
    n>>=1;
    int tmp[]={foo(i,j,n),foo(i+n,j,n),foo(i,j+n,n),foo(i+n,j+n,n)};
    sort(tmp,tmp+4);
    return tmp[2];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;cin>>n;
    f(i,0,n)f(j,0,n)cin>>a[i][j];
    cout<<foo(0,0,n);
    return 0;
}
