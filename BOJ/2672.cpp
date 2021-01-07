#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n;
struct info{
	double x,y,w,h;
} p[30];

bool compx(info &a, info &b){
	return a.x<b.x;
}

double nextX(double sx){
	double nx=1e5;
	f(i,0,n){
		if(sx<p[i].x)nx=min(nx,p[i].x);
		if(sx<p[i].x+p[i].w)nx=min(nx,p[i].x+p[i].w);
	}
	return nx==1e5?-1:nx;
}

double nextY(double sy,double sx,double ex){
	double ny=1e5;
	f(i,0,n)if(p[i].x<=sx&&ex<=p[i].x+p[i].w){
		if(sy<p[i].y)ny=min(ny,p[i].y);
		if(sy<p[i].y+p[i].h)ny=min(ny,p[i].y+p[i].h);
	}
	return ny==1e5?-1:ny;
}

bool isValid(double sx,double ex,double sy,double ey){
	f(i,0,n)if(p[i].x<=sx&&
			   ex<=p[i].x+p[i].w&&
			   p[i].y<=sy&&
			   ey<=p[i].y+p[i].h)return true;
	return false;
}

double minY(double sx,double ex){
	double my=1e5;
	f(i,0,n)if(p[i].x<=sx&&ex<=p[i].x+p[i].w)my=min(my,p[i].y);
	return my;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n)cin>>p[i].x>>p[i].y>>p[i].w>>p[i].h;
	sort(p,p+n,compx);
	
	double sx=p[0].x,ex=nextX(sx),ans=0;
	while(1){
		double w=ex-sx,sy=minY(sx,ex),ey=nextY(sy,sx,ex);
		while(1){
			if(ey==-1)break;
			if(isValid(sx,ex,sy,ey))ans+=w*(ey-sy);
			sy=ey;
			ey=nextY(sy,sx,ex);
		}
		sx=ex;
		ex=nextX(sx);
		if(ex==-1)break;
	}
	if((int)(ans*100)%100)cout<<fixed<<setprecision(2)<<ans;
	else cout<<ans;
	
	return 0;
}
