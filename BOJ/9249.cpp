#include "bits/stdc++.h"
using namespace std;

#define MAXN 200001
#define f(i,l,r) for(int i = l; i < r; ++i)

int L, T, SFX[MAXN], LCP[MAXN];
string S, B;
struct info {
    int idx, rank;
};

void makeSuffixArray() {
    info p[MAXN];
    int q[MAXN];
    f(i,0,L) {
        p[i].idx = i;
        p[i].rank = S[i]-'a';
    }
    
    for(int t = 1; t < L; t <<= 1) {
        memset(q, -1, sizeof(int)*L);
        f(i,0,L){
            int j = p[i].idx-t;
            if(j >= 0) q[j] = p[i].rank;
        }
        
        sort(p, p+L, [&](info i, info j){
            return i.rank == j.rank ? q[i.idx] < q[j.idx] : i.rank < j.rank;
        });
        
        int rank = 0;
        int prevRank = p[0].rank;
        p[0].rank = rank;
        f(i,1,L){
            if (prevRank != p[i].rank || q[p[i-1].idx] != q[p[i].idx]) ++rank;
            prevRank = p[i].rank;
            p[i].rank = rank;
        }
    }
    
    f(i,0,L) SFX[i] = p[i].idx;
}

void makeLCP() {
    int rev[MAXN];
    f(i,0,L) rev[SFX[i]] = i;
    
    LCP[0] = 0;
    int d = 0;
    f(i,0,L) if(rev[i]) {
        int j = SFX[rev[i]-1];
        while(j+d < L && S[SFX[rev[i]]+d] == S[j+d]) ++d;
        LCP[rev[i]] = d;
        if (d > 0) --d;
    }
}

void sol() {
    cin>>S>>B;
    
    int lenA = S.length(), lenB = B.length();
    L = lenA + lenB + 1;
    S.append("#"); S.append(B);
    
    makeSuffixArray();
    makeLCP();
    
    int maxLen = 0, beginIdx;
    int i = L-1;
    bool isA = SFX[i] < lenA;
    while (i>0) {
        int val;
        while (isA == (SFX[i] < lenA)) {
            val = LCP[i];
            --i;
        }
        isA = !isA;
        if (i >= 0 && maxLen < val) {
            maxLen = val;
            beginIdx = SFX[i+1];
        }
    }
    cout<<maxLen<<'\n'<<S.substr(beginIdx, maxLen);;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sol();
    return 0;
}
