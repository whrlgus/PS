#include<bits/stdc++.h>
using namespace std;

int n,arr[1000];

void bubbleSort(){
	for(int i=n-1;i>0;--i){
		for(int j=0;j<i;++j){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
}

void selectionSort(){
	for(int i=0;i<n-1;++i){
		int idx=i;
		for(int j=i+1;j<n;++j){
			if(arr[idx]>arr[j]){
				idx=j;
			}
		}
		swap(arr[i],arr[idx]);
	}
}

void insertionSort(){
	for(int i=1;i<n;++i){
		for(int j=i;j>0&&arr[j-1]>arr[j];--j){
			swap(arr[j-1],arr[j]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>arr[i];
//	bubbleSort();
//	selectionSort();
	insertionSort();
	for(int i=0;i<n;++i)cout<<arr[i]<<'\n';
	return 0;
}
