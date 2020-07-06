#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;
const int MX = 5e6;
bool p[MX] = { true,true }, used[MX];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	for (int i = 4; i < MX; i += 2)p[i] = true;
	int r = sqrt(MX);
	for (int i = 3; i <= r; i += 2) for (int j = i+i; j < MX; j += i)p[j] = true;
	
	set<int> sa,sb;
	set<int>::iterator it;
	int n; cin >> n;
	long long suma=0, sumb=0;
	
	while (n--) {
		int a, b; cin >> a >> b;
		if (used[a]) suma -= 1000;
		else if (!p[a])sa.insert(a), used[a] = true;
		else if (sb.size() >= 3)sumb += *(------(set<int>::iterator)sb.end());
		else sumb += 1000;
		
		if (used[b]) sumb -= 1000;
		else if (!p[b])sb.insert(b), used[b] = true;
		else if (sa.size() >= 3)suma += *(------(set<int>::iterator)sa.end());
		else suma += 1000;
	}
	if (suma == sumb)cout << "우열을 가릴 수 없음";
	else if (suma < sumb)cout << "소수 마스터 갓규성";
	else cout << "소수의 신 갓대웅";
	return 0;
}
