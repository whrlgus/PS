#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
#define swap(a,b) a^=b^=a^=b
using namespace std;

const int MAXN=1e5+1;
int heap[MAXN],size;

int pop_heap(){
	if(!size) return 0;
	int ret=heap[1];
	heap[1]=heap[size--];
	int i=1,j;
	while((i<<1)<=size){
		j=i<<1;
		if((j|1)<=size&&heap[j]<heap[j|1])j|=1;
		if(heap[i]<heap[j])swap(heap[i],heap[j]),i=j;
		else break;
	}
	return ret;
}

void push_heap(int x){
	heap[++size]=x;
	int i=size,j;
	while((j=(i>>1))){
		if(heap[i]>heap[j])swap(heap[i],heap[j]),i=j;
		else break;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	while(n--){
		int x;cin>>x;
		if(x)push_heap(x);
		else cout<<pop_heap()<<'\n';
	}
	return 0;
}
