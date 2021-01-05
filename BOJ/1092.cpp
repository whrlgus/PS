#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n,m,c[50],w[10000],mxc,mxw;

int ceil(int x,int y){
	return x/y+(x%y!=0);
}

int sol(){
	if(mxc<mxw)return -1;
	
	sort(c,c+n);
	sort(w,w+m);
	int cnt,size=ceil(m,n),j=0;
	f(i,0,n){
		cnt=0;
		while(j<m){
			if(w[j]>c[i]){
				size=max(size,ceil(m-j,n-i-1));
				break;
			}
			++j;
			if(++cnt==size)break;
		}
	}
	
	return size;
}

void input(int &x,int &y,int *arr){
	cin>>x;
	f(i,0,x){
		cin>>arr[i];
		y=max(y,arr[i]);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input(n,mxc,c);
	input(m,mxw,w);
	cout<<sol();
	
	return 0;
}
