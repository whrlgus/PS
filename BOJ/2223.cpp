#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int MAXN=2001;
int N,X,Y,p[MAXN][2];
char c[MAXN<<1];


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>N>>c+1>>X>>Y;
    
    int size=N<<1,idx=1,x,y;
    stack<int> s;
    f(i,1,size){
        if(c[i]=='1'){
            if(i==X)x=s.top();
            if(i==Y)y=s.top();
            p[s.top()][1]=i;
            s.pop();
        }else{
            if(i==X)x=idx;
            if(i==Y)y=idx;
            s.push(idx);
            p[idx++][0]=i;
        }
        
    }
    
    int mn=min(p[x][0],p[y][0]),mx=max(p[x][1],p[y][1]),t=1;
    f(i,2,N)if(p[i][0]<=mn&&p[i][1]>=mx){
        if((p[t][1]-p[t][0])>(p[i][1]-p[i][0]))t=i;
    }
    cout<<p[t][0]<<' '<<p[t][1];
    
    return 0;
}


