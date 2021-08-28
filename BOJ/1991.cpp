#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

map<char, pair<char, char>> m;

void sol(char r, int op) {
    if(r=='.')return;
    if(op==0)cout<<r;
    if(m[r].first)sol(m[r].first,op);
    if(op==1)cout<<r;
    if(m[r].second)sol(m[r].second,op);
    if(op==2)cout<<r;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;cin>>n;
    f(i,0,n){
        char a,b,c;cin>>a>>b>>c;
        m[a]={b,c};
    }
    
    f(i,0,3){
        sol('A',i);
        cout<<'\n';
    }
    
    return 0;
}
