#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int INF=5e4+1;
int s[INF];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;cin>>n;
    while(n--){
        int num;cin>>num;
        s[num]=1;
    }
    int m;cin>>m;
    
    f(i,1,INF){
        if(!s[i])s[i]=INF;
        f(j,1,i)if(s[j]&&s[i-j])s[i]=min(s[i],s[j]+s[i-j]);
        if(s[i]>m){
            cout<<((i&1)?"jjak":"hol")<<"soon win at "<<i;
            break;
        }
    }
    
    return 0;
}
