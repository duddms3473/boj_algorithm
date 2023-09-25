#include<iostream>

using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

int n, q;
int arr[64][64];


void rotate(int cy, int cx, int len, int unit){
	if (len == unit) {
		int back[64][64];
		for (int y= 0; y < len; ++y) {
			for (int x = 0; x < len; ++x) {
				back[cy + x][cx + len - y - 1] = arr[cy + y][cx + x];
			}
		}
		for (int y = 0; y < len; ++y) {
			for (int x = 0; x < len; ++x) {
				arr[cy + y][cx + x] = back[cy + y][cx + x];
			}
		}
		return;
	}
	len /= 2;
	rotate(cy, cx, len, unit);
	rotate(cy+len, cx, len, unit);
	rotate(cy, cx+len, len, unit);
	rotate(cy+len, cx+len, len, unit);
}
void melt() {
	int len = (1 << n);
	int back[64][64];

	for (int y = 0; y < len; ++y) {
		for (int x = 0; x < len; ++x) {
			int cnt = 0;
			for (int d = 0; d < 4; ++d) {
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (ny < 0 or ny >= len or nx < 0 or nx >= len) {
					continue;
				}
				if (arr[ny][nx] == 0) {
					continue;
				}
				++cnt;
			}
			if (cnt >= 3 or arr[y][x] == 0) {
				back[y][x] = arr[y][x];
			}
			else {
				back[y][x] = arr[y][x] - 1;
			}

		}
	}
	for (int y = 0; y < len; ++y) {
		for (int x = 0; x < len; ++x) {
			arr[y][x] = back[y][x];
		}
	}
}

void dfs(int y, int x, bool visited[64][64], int& size) { //앰퍼샌드 사용
	++size;
	int len = (1 << n);
	for (int d = 0; d < 4; ++d) {
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (ny < 0 or ny >= len or nx < 0 or nx >= len) {
			continue;
		}
		if (visited[ny][nx] == true or arr[ny][nx] == 0) {
			continue;
		}
		visited[ny][nx] = true;
		dfs(ny, nx, visited, size);
	}

}
int main() {
	cin >> n >> q;
	int len = (1 << n); //1을 n번 왼쪽으로 이동

	for (int y = 0; y < len; ++y) {
		for (int x = 0; x < len; ++x) {
			cin >> arr[y][x];
		}
	}

	while (q--) {
		int l;
		cin >> l;
		if (l > 0) { //얼음이 존재할 경우
			rotate(0, 0, len, (1 << l));

		}
		melt();
	}

	//가장 큰 값 구하기
	int total = 0, maxsize = 0;
	bool visited[64][64] = { false, };

	for (int y = 0; y < len; ++y) {
		for (int x = 0; x < len; ++x) {
			total += arr[y][x];

			if (visited[y][x]==false and arr[y][x] != 0) {
				visited[y][x] = true;
				int cursize = 0;
				dfs(y, x, visited, cursize);
				if (maxsize < cursize) {
					maxsize = cursize;
				}
			}
		}
	}
	cout << total << "\n";
	cout<<maxsize << "\n";

	return 0;
}