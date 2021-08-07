#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

typedef pair<int,int> pii;
bool chk[8][8];

int di[]={-2,-2,-1,-1,1,1,2,2}, dj[]={-1,1,-2,2,-2,2,-1,1};

int minDist(pii a,pii b) {
    memset(chk,0,sizeof(chk));
    queue<pii> q;
    q.push(a);
    chk[a.first][a.second]=1;
    
    int ret=0;
    while(!q.empty()){
        int cnt=q.size();
        while(cnt--){
            pii &tmp=q.front();
            if(tmp.first==b.first&&tmp.second==b.second)return ret;
            f(d,0,8){
                int ni=tmp.first+di[d],nj=tmp.second+dj[d];
                if(ni<0||ni>=8||nj<0||nj>=8||chk[ni][nj])continue;
                q.push(pii(ni,nj));
                chk[ni][nj]=1;
            }
            q.pop();
        }
        ++ret;
    }
    
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string a,b;
    while(cin>>a>>b) {
        int n=minDist(pii(a[0]-'a',a[1]-'1'),pii(b[0]-'a',b[1]-'1'));
        cout<<"To get from "<<a<<" to "<<b<<" takes "<<n<<" knight moves.\n";
    }
    return 0;
}


