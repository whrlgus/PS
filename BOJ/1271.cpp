#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
#define fr(i,l,r) for(int i=l;i>=r;--i)
using namespace std;

bool isBigger(string a, string b){
	if(a.length()==b.length()){
		f(i,0,a.length())if(a[i]!=b[i]){
			if(a[i]>b[i])return true;
			break;
		}
		return false;
	}
	return a.length()>b.length();
}

int getLen(string a, string b){
	if(a.length()<b.length())return 0;
	if(!isBigger(b,a.substr(0,b.length())))return b.length();
	return a.length()==b.length()?0:b.length()+1;
}

string getVal(string a, int num){
	int carry=0;
	string ret="";
	fr(i,a.length()-1,0){
		int tmp=carry+(a[i]-'0')*num;
		ret.push_back(tmp%10+'0');
		carry=tmp/10;
	}
	if(carry)ret.push_back(carry+'0');
	reverse(ret.begin(),ret.end());
	return ret;
}

int getQuotient(string a, string b){
	f(i,2,10)if(isBigger(getVal(b, i),a))return i-1;
	return 9;
}

void borrow(string &a, int pos){
	int j=pos-1;
	fr(i,j,0)if(a[i]!='0'){
		a[i]-=1;
		j=i;
		break;
	}
	f(i,j+1,pos)a[i]='9';
}

string getDiff(string a, string b){
	if(a.length()>b.length())b="0"+b;
	string ret(a.length(),'0');
	fr(i,a.length()-1,0){
		if(a[i]<b[i]){
			borrow(a,i);
			ret[i]=10+a[i]-b[i]+'0';
		}else ret[i]=a[i]-b[i]+'0';
	}
	int j=0;
	f(i,0,ret.length())if(ret[i]!='0'){
		j=i;
		break;
	}
	return ret.substr(j);
}

void removeZero(string &a){
	int j=a.length();
	f(i,0,a.length())if(a[i]!='0'){
		j=i;
		break;
	}
	a=a.substr(j);
}

void sol(string n, string m){
	string quotient(n.length(),'0');
	
	int len;
	while((len=getLen(n,m))){
		string tmp=n.substr(0,len);
		int quo=getQuotient(tmp, m);
		quotient[n.length()-len]=quo+'0';
		n=getDiff(tmp, getVal(m, quo))+(len!=n.length()?n.substr(len):"");
		removeZero(n);
	}
	fr(i,quotient.length()-1,0){
		if(quotient[i]!='0')break;
		quotient.pop_back();
	}
	reverse(quotient.begin(),quotient.end());
	if(quotient=="")quotient="0";
	if(n=="")n="0";
	
	cout<<n<<" "<<m<<endl;
	cout<<quotient<<" "<<n<<endl;
	cout<<endl;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string n,m;cin>>n>>m;
	string quotient(n.length(),'0');

	int len;
	while((len=getLen(n,m))){
		string tmp=n.substr(0,len);
		int quo=getQuotient(tmp, m);
		quotient[n.length()-len]=quo+'0';
		n=getDiff(tmp, getVal(m, quo))+n.substr(len);
		removeZero(n);
	}
	fr(i,quotient.length()-1,0){
		if(quotient[i]!='0')break;
		quotient.pop_back();
	}
	reverse(quotient.begin(),quotient.end());
	cout<<(quotient==""?"0":quotient)<<'\n';
	cout<<(n==""?"0":n);
	return 0;
}
