#include <bits/stdc++.h>

#define endl '\n'
#define rep(V,S,T) for(int V=S; V<T; ++V)

using namespace std;

bool board[20][20];
vector<pair<const int, const int>> type[4] = {
	{{0,0},{0,1},{1,0}}, // left-top
	{{0,0},{0,1},{1,1}}, // right-top
	{{0,0},{1,0},{1,-1}}, // right-bottom
	{{0,0},{1,0},{1,1}} // left-bottom
};
int H, W;

inline bool avail(int y, int x, int t) {
	for (auto d : type[t]) {
		int ny = y + d.first, nx = x + d.second;
		if (ny < 0 || nx < 0 || ny >= H || nx >= W) return false;
		if (!board[ny][nx]) return false;
	}
	return true;
}

int cover(int y, int x, int t) {
	int ans = 0;

	for (auto d : type[t])
		board[y + d.first][x + d.second] = false;

	bool done = true;
	rep(i, 0, H)
		rep(j, 0, W)
		if (board[i][j]) {
			done = false;
			rep(t, 0, 4)
				if (avail(i, j, t)) ans += cover(i, j, t);
			goto L1; // escape nested loop
		}
L1:
	if (done) ans += 1;

	for (auto d : type[t])
		board[y + d.first][x + d.second] = true;

	return ans;
}

int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		int ans = 0;
		scanf("%d %d", &H, &W);
		char input;
		rep(i, 0, H) {
			rep(j, 0, W) {
				scanf(" %c", &input);
				board[i][j] = input == '.' ? true : false;
			}
		} // end of input

		int y = -1, x = -1;
		rep(i, 0, H)
			rep(j, 0, W)
			if (board[i][j]) {
				y = i, x = j;
				goto L2; // found space
			}
		goto L3; // no space
	L2:
		rep(t, 0, 4)
			if (avail(y, x, t)) ans += cover(y, x, t);
	L3:
		printf("%d\n", ans);
	}
}
