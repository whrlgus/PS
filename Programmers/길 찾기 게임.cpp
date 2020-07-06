#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

struct node{
	int no,x,y;
	bool operator<(const node& oth)const{
		return x<oth.x;
	}
}inOrder[10000];

void traversal(vector<int> &v,int l, int r, bool k){
	if(l>=r){
		if(l==r)v.push_back(inOrder[l].no);
		return;
	}
	int i=l,j=r;
	while(i<j)inOrder[i].y<inOrder[j].y?++i:--j;
	if(k)v.push_back(inOrder[i].no);
	traversal(v,l,i-1,k);
	traversal(v,i+1,r,k);
	if(!k)v.push_back(inOrder[i].no);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	int no=0;
	f(i,0,nodeinfo.size())inOrder[i]={++no,nodeinfo[i][0],nodeinfo[i][1]};
	sort(inOrder, inOrder+no);

	vector<vector<int>> answer(2);
	traversal(answer[0],0,no-1,true);
	traversal(answer[1],0,no-1,false);
	return answer;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<vector<int>> result=solution({{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}});
	return 0;
}
