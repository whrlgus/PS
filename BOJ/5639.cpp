#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int arr[10000];

void sol(int* l,int* r){
    if(l>=r)return;
    int* tmp=upper_bound(l+1,r,*l);
    sol(l+1,tmp);
    sol(tmp,r);
    cout<<*l<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n=0;
    while(cin>>arr[n++]);
    sol(arr,arr+n-1);
    
    return 0;
}
