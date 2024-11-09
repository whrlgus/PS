#include "bits/stdc++.h"
using namespace std;

#define MAXN 200001

int n, L, T, SFX[MAXN], LCP[MAXN];
char S[MAXN];
struct info {
    int idx, rank;
};

void makeSuffixArray() {
    info p[MAXN];
    int q[MAXN];
    for(int i = 0; i < n; ++i){
        p[i].idx = i;
        p[i].rank = S[i]-'a';
        q[i]=p[i].rank;
    }
    q[n] = -1;
    
    for(int t=1; t>>1 <= n; t<<=1) {
        sort(p, p+n, [&](info i, info j){
            return i.rank == j.rank ? q[i.idx+t] < q[j.idx+t] : i.rank < j.rank;
        });
        
        int rank = 0;
        p[0].rank = rank;
        for(int i=1; i<n; ++i){
            if (q[p[i].idx] != q[p[i-1].idx] || q[p[i].idx+t] != q[p[i-1].idx+t])++rank;
            p[i].rank = rank;
        }
        
        for(int i=0; i<n; ++i)q[p[i].idx]=p[i].rank;
    }
    
    for(int i=0; i<n; ++i)SFX[i]=p[i].idx;
}

void makeLCP() {
    int rev[MAXN];
    for(int i=0;i<n;++i)rev[SFX[i]]=i;
    
    int i=0;
    while(i<n) {
        int cnt=0;
        if(rev[i])while(S[SFX[rev[i]]+cnt] == S[SFX[rev[i]-1]+cnt])++cnt;
        LCP[rev[i]]=cnt;
        
        while(cnt>0)LCP[rev[++i]]=--cnt;
        ++i;
    }
}

int sol() {
    cin>>L>>S;
    copy(S,S+L-1,S+L);
    n=L*2-1;
    
    makeSuffixArray();
    makeLCP();
    
    LCP[n]=0;
    for(int i=0;i<n;++i)
        if (SFX[i]<L&&LCP[i+1]<L)
            return SFX[i];
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--) cout<<sol()<<'\n';
    return 0;
}
