#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int n,a[11],cnt[4],mx=-1e9,mn=1e9,ops[10],priority[]={0,0,1,1};

int calc(int num1,int op,int num2){
	if(op==0)return num1+num2;
	if(op==1)return num1-num2;
	if(op==2)return num1*num2;
	return num1/num2;
}

int calculation(){
	stack<int> num,op;
	num.push(a[0]);
	f(i,1,n){
		while(!op.empty()&&priority[op.top()]>=priority[ops[i-1]]){
			int num2=num.top();num.pop();
			int num1=num.top();num.pop();
			num.push(calc(num1,op.top(),num2));
			op.pop();
		}
		num.push(a[i]);
		op.push(ops[i-1]);
	}
	
	int ret=num.top();num.pop();
	while(!op.empty()){
		ret=calc(num.top(),op.top(),ret);
		num.pop();op.pop();
	}
	return ret;
}

void permutation(int l, int r){
	if(l+1==r){
		int result=calculation();
		mx=max(mx,result);
		mn=min(mn,result);
		return;
	}
	bool used[4]{};
	f(i,l,r){
		if(used[ops[i]])continue;
		used[ops[i]]=true;
		swap(ops[l],ops[i]);
		permutation(l+1,r);
		swap(ops[l],ops[i]);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	f(i,0,n)cin>>a[i];
	f(i,0,4)cin>>cnt[i];
	
	int idx=0;
	f(i,0,4)while(cnt[i]--)ops[idx++]=i;
	permutation(0, n-1);
	cout<<mx<<'\n'<<mn;
	
	return 0;
}
