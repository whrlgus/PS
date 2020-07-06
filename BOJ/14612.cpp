#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

struct info {
	int table,sec;
	bool operator<(const info& oth)const {
		return sec == oth.sec ? table < oth.table : sec < oth.sec;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, sec, table;
	cin >> n >> m;
	vector<info>v;
	while (n--) {
		string str; cin >> str;
		switch(str[0]){
		case 'o':
			 cin >> table >> sec;
			v.push_back({ table,sec });
			break;
		case 's':
			sort(v.begin(), v.end());
			break;
		case 'c':
			cin >> table;
			vector<info>::iterator it = v.begin();
			while (it->table != table)++it;
			v.erase(it);
		}
		if (v.size())for (info& e : v)cout << e.table << ' ';
		else cout << "sleep";
		cout << '\n';
	}

	return 0;
}
