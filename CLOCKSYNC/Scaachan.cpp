#include <bits/stdc++.h>

#define endl '\n'
#define rep(V,S,T) for(int V=S; V<T; ++V)

using namespace std;

vector<vector<int>> sw{
	{ 0, 1, 2 },
	{ 3, 7, 9, 11 },
	{ 4, 10, 14, 15 },
	{ 0, 4, 5, 6, 7 },
	{ 6, 7, 8, 10, 12 },
	{ 0, 2, 14, 15 },
	{ 3, 14, 15 },
	{ 4, 5, 7, 14, 15 },
	{ 1, 2, 3, 4, 5 },
	{ 3, 4, 5, 9, 13 }
};
int status[16]; // current clock status

int press(int n, int cnt) {
	if (cnt) {
		for (auto i : sw[n])
			rep(j, 0, cnt)
				status[i] += status[i] ? -1 : 3;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int TC; cin >> TC;
	while (TC--) {
		int h, twelve = 0, ans = 0;

		rep(i, 0, 16) {
			cin >> h;
			if (h == 12) twelve++;
			status[i] = h % 4;
		} // end of input

		if (twelve == 16) { // all the clocks are at 12
			cout << 0 << endl;
			continue;
		}

		if (status[8] != status[12]) {
			cout << -1 << endl;
			continue;
		}
		ans += press(4, status[8]);

		ans += press(1, status[11]);
		if (status[9] != status[13]) {
			cout << -1 << endl;
			continue;
		}
		ans += press(9, status[13]);

		ans += press(3, status[6]);
		ans += press(2, status[10]);
		ans += press(7, status[7]);

		if (status[4] != status[5]) {
			cout << -1 << endl;
			continue;
		}
		ans += press(8, status[4]);

		ans += press(0, status[1]);
		ans += press(6, status[3]);

		bool s1 = status[0] != status[2];
		bool s2 = status[14] != status[15];
		bool s3 = status[2] != status[14];
		if (s1 || s2 || s3) {
			cout << -1 << endl;
			continue;
		}
		ans += press(5, status[0]);

		cout << ans << endl;
	}
}
