#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
#define fr(i,l,r) for(int i=l;i>=r;--i)
using namespace std;

struct info {
    int s,p,o;
    bool operator <(const info &oth) const{
        return p>oth.p;
    }
}a[100];
int s[10001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        f(i,0,m)cin>>a[i].s>>a[i].p>>a[i].o;
        sort(a,a+m);
        memset(s,63,sizeof(s));
        s[0]=0;
        f(i,0,m){
            int val=a[i].s*a[i].p+a[i].o;
            fr(j,n,a[i].s)s[j]=min(s[j],val+s[j-a[i].s]);
            fr(j,a[i].s,1){
                s[j]=min(s[j],val);
                val-=a[i].p;
            }
        }
        cout<<s[n]<<'\n';
    }
    return 0;
}
