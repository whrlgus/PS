#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

struct Point{int x,y;} a[3000][2];
int n,p[3000],cnt[3000],ans[2];
bool chk[3000];

int root(int i){
	return p[i]==i?i:p[i]=root(p[i]);
}

int orientation(Point p, Point q, Point r){
	int val=(q.y - p.y) * (r.x - q.x)
	- (q.x - p.x) * (r.y - q.y);
	return val==0?0:val>0?1:2;
}

bool onSegment(Point p, Point q, Point r){
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
	   return true;
	return false;
}

bool isValid(int i,int j){
	Point p1=a[i][0],q1=a[i][1],p2=a[j][0],q2=a[j][1];
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);
	if (o1!=o2&&o3!=o4)return true;
	
	if ((o1 == 0 && onSegment(p1, p2, q1))||
		(o2 == 0 && onSegment(p1, q2, q1))||
		(o3 == 0 && onSegment(p2, p1, q2))||
		(o4 == 0 && onSegment(p2, q1, q2))) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n){
		cin>>a[i][0].x>>a[i][0].y>>a[i][1].x>>a[i][1].y;
		p[i]=i;
	}
	
	f(i,0,n)f(j,i,n)if(isValid(i,j)){
		int ri=root(i),rj=root(j);
		if(ri!=rj)p[rj]=ri;
	}
	
	f(i,0,n){
		int ri=root(i);
		if(!chk[ri])chk[ri]=true,++ans[0];
		ans[1]=max(ans[1],++cnt[ri]);
	}
	cout<<ans[0]<<'\n'<<ans[1];
	
	return 0;
}
