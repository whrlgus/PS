#include <bits/stdc++.h>
using namespace std;

const int MAXN=2e5;
bool vis[MAXN];
int prior[MAXN],hang[MAXN];
vector<int> edge[MAXN];

void visit(int v){
    if(vis[v])return;
    if(!vis[prior[v]]){
        hang[prior[v]]=v;
        return;
    }
    vis[v]=true;
    visit(hang[v]);
    for(int u:edge[v])visit(u);
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    for(auto &a:path){
        edge[a[0]].push_back(a[1]);
        edge[a[1]].push_back(a[0]);
    }
    for(auto &a:order)prior[a[1]]=a[0];

    if(prior[0])return false;

    vis[0]=true;
    for(int u:edge[0])visit(u);
    for(int i=0;i<n;++i)if(!vis[i])return false;
    return true;
}
