#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

const ll BIG = 1e18 + 1;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;

void solve();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

void solve() {
	int n;
	cin >> n;
	vector<int> P(n, 0);
	vector<int> G(n, 0);
	set<vector<int>> S;
	for (int i = 0; i < n; i ++) cin >> P[i];
	bool langsungsatu = true;
	for (int i = 0; i < n; i ++) {
		if (i != P[i] - 1)
			langsungsatu = false;
	}
	if (langsungsatu) {
		cout << 1 << endl;
		return;
	}
	vector<bool> sudah(n, false);
	ll count = 0;
//	int kk = 0;
	do {
//		cout << "#" << kk++ << endl;
		S.insert(P);
		for (int i = 0; i < n; i ++)
			G[i] = P[P[i] - 1];
		for (int i = 0; i < n; i ++)
			P[i] = G[i];
		bool bersih = false;
		for (int i = 0; i < n; i ++) {
			if (i == (P[i] - 1) && !sudah[i]) {
				sudah[i] = true;
				bersih = true;
			}
		}
		if (bersih) {
			count += (ll) S.size();
			S.clear();
		}
//		for (int i = 0; i < n; i ++)
//			cout << P[i] << " ";
//		cout << endl;
//		cout << "set:" << S.size() << endl;
//		for (auto it = S.begin(); it != S.end(); it++) {
//			for (int i = 0; i < n; i ++)
//				cout << (*it)[i] << " ";
//			cout << endl;
//		}
//		cout << (count) << " + "<< (S.size()) << endl;
	}
	while (S.find(P) == S.end());
	cout << (count + S.size()) << endl;
}

