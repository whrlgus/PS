#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
#define fr(i,l,r) for(int i=l;i>=r;--i)
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string a, b; cin >> a >> b;
	int start = 0,end=0;
	string ans(a.length() + b.length(), '0');
	fr(i, b.length() - 1, 0) {
		if (b[i] == '1') {
			bool carry = false;
			fr(j, a.length() - 1, 0) if(carry||a[j]=='1'){
				int idx = start + a.length() - 1 - j;
				if (ans[idx] == '1') {
					ans[idx] = (carry && a[j]=='1'?'1':'0');
					carry = true;
				}
				else {
					if (carry && a[j] == '1') {
						carry = true;
						ans[idx] = '0';
					}
					else {
						carry = false;
						ans[idx] = '1';
					}
				}
			}
			int j = a.length() + start;
			while (carry) {
				if (ans[j] == '1')
					ans[j] = '0';
				else {
					ans[j] = '1';
					carry = false;
				}
				++j;
			}
			end = max(end, j);
		}
		++start;
	}
	fr(i, end-1, 0)cout << ans[i];
	

	return 0;
}
