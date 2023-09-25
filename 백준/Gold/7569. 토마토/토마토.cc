#include<iostream>
#include<queue>
using namespace std;

struct tomato {
	int x, y, z, day;
};
int n, m, h,maxday=0;
int arr[100][100][100];
queue<tomato> q;
const int dz[] = { -1,1,0,0,0,0 };
const int dy[] = { 0,0,-1,1,0,0 };
const int dx[] = { 0,0,0,0,-1,1 };

void bfs() {
	while (!q.empty()) {
		tomato t = q.front();
		q.pop();
		int tz = t.z, ty = t.y, tx = t.x, tday = t.day;

		for (int i = 0; i < 6; ++i) {
			int nz = tz + dz[i];
			int ny = ty + dy[i];
			int nx = tx + dx[i];
			if (nz < 0 or ny < 0 or nx < 0 or nz >= h or ny >= m or nx >= n) continue;
			if (arr[nz][ny][nx] == 0) {
				arr[nz][ny][nx] = 1;
				q.push({ nx,ny,nz,tday + 1 });
				if ((tday + 1) > maxday) maxday = (tday + 1);
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> h;
	bool flag = true;
	for (int z = 0; z < h; ++z) {
		for (int y = 0; y < m; ++y) {
			for (int x = 0; x < n; ++x) {
				cin >> arr[z][y][x];
				if (arr[z][y][x] == 1) {
					q.push({ x,y,z,0 });
				}
				if (arr[z][y][x] == 0) {
					flag = false;
				}
			}
		}
	}
	if (flag == true) {
		cout << 0 << "\n";
		return 0;
	}

	bfs();

	for (int z = 0; z < h; ++z) {
		for (int y = 0; y < m; ++y) {
			for (int x = 0; x < n; ++x) {
				if (arr[z][y][x] == 0) {
					cout << -1 << "\n";
					return 0;
				}
			}
		}
	}
	cout << maxday << "\n";
	return 0;
}