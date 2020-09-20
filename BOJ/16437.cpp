#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;i++)
#define LEN 123457
using namespace std;

int n,route[LEN],wolves[LEN],sheep[LEN]{};
long long ans=0;

int move(int cnt,int i){
    if(i==1){
        ans+=cnt;
        return 1;
    }
    if(cnt<wolves[i]){
        wolves[i]-=cnt;
        return i;
    }else{
        cnt-=wolves[i];
        wolves[i]=0;
        return route[i]=move(cnt,route[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    
    cin>>n;
    f(i,2,n){
        char t;int a,p;cin>>t>>a>>p;
        if(t=='S') sheep[i]=a;
        else wolves[i]=a;
        route[i]=p;
    }
    
    f(i,1,n)if(sheep[i])move(sheep[i],route[i]);
    cout<<ans;
    return 0;
}
