#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MXN=5000;
int n,k,a[MXN];
bool chk[MXN];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    f(i,0,n)cin>>a[i];
    
    stack<int> s;
    s.push(0);
    while(!s.empty()){
        int i=s.top();
        s.pop();
        
        f(j,i+1,n)if((j-i)*(1+abs(a[i]-a[j]))<=k&&!chk[j]){
            chk[j]=true;
            s.push(j);
        }
        
        if(chk[n-1]){
            cout<<"YES";
            exit(0);
        }
    }
    
    cout<<"NO";
    return 0;
}

