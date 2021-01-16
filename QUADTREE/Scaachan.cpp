#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

string rcs(string::iterator &it) {
	char ch = *it;
	if (ch == 'b') return "b";
	if (ch == 'w') return "w";

	string r1 = rcs(++it);
	string r2 = rcs(++it);
	string r3 = rcs(++it);
	string r4 = rcs(++it);

	return "x" + r3 + r4 + r1 + r2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int TC; cin >> TC;
	string s;
	while (TC--) {
		cin >> s;
		auto it = s.begin();
		cout << rcs(it) << endl;
	}
}
