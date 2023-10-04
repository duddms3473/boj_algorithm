#include<iostream>
using namespace std;

struct Point {
	int x, y;
};

int n, m, ans = 0;

Point dest[16];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int grid[5][5];
bool visit[5][5] = { 0, };

void dfs(Point cur, int index) {
	if ((cur.x == dest[index].x) and (cur.y == dest[index].y)) {
		if (index == (m - 1)) {
			ans++;
			return;
		}
		index++;
	}
	int curx = cur.x;
	int cury = cur.y;

	visit[curx][cury] = true;

	for (int i = 0; i < 4; i++) {
		int nextx = curx + dx[i];
		int nexty = cury + dy[i];

		if (nextx < 1 or nexty < 1 or nextx > n or nexty > n) { //격자를 벗어난 경우
			continue;
		}
		if (visit[nextx][nexty] == true) { //이미 방문한 경우
			continue;
		}
		if (grid[nextx][nexty] == 1) { //벽일경우
			continue;
		}

		dfs({ nextx,nexty }, index);
	}
	visit[curx][cury] = false;
}

int main(int argc, char** argv)
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> grid[i][j];
		}
	}
	int x, y;
	Point tmp;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		tmp.x = x; tmp.y = y;
		dest[i] = tmp;
	}

	dfs(dest[0], 1);

	cout << ans << "\n";

	return 0;
}
