#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MAXN=1e6;
int n,arr[MAXN];

int partition(int l, int r){
    swap(arr[r], arr[(l+r)/2]);
	int pivot=arr[r],pi=l-1;
	for(int i=l;i<r;++i){
		if(arr[i]<pivot){
			++pi;
			swap(arr[i],arr[pi]);
		}
	}
	arr[r]=arr[++pi];
	arr[pi]=pivot;
	return pi;
}

void quickSort(int l, int r){
	if(l>=r)return;
	int pi=partition(l,r);
	quickSort(l,pi-1);
	quickSort(pi+1,r);
}

void merge(int l, int m, int r){
	int tmp[MAXN];
	for(int i=l;i<=r;++i)tmp[i]=arr[i];
	int i=l,j=m+1,idx=l;
	while(i<=m&&j<=r)arr[idx++]=tmp[i]<tmp[j]?tmp[i++]:tmp[j++];
	while(i<=m)arr[idx++]=tmp[i++];
	while(j<=r)arr[idx++]=tmp[j++];
}

void mergeSort(int l, int r){
	if(l>=r)return;
	int m=(l+r)>>1;
	mergeSort(l, m);
	mergeSort(m+1, r);
	merge(l,m,r);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>arr[i];
//	quickSort(0,n-1);
	mergeSort(0,n-1);
	for(int i=0;i<n;++i)cout<<arr[i]<<'\n';
	return 0;
}
