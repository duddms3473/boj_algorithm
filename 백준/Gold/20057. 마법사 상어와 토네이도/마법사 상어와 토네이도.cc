#include<iostream>
#include<vector>
using namespace std;
int n;
int a[499][499];

//left-down-right-up
int dy[] = { 0,1,0,-1 };
int dx[] = { -1,0,1,0 };

int windy[4][9] = {
	{-1,1,-2,2,0,-1,1,-1,1},	//left
	{-1,-1,0,0,2,0,0,1,1},		//down
	{1,-1,2,-2,0,1,-1,1,-1},	//right
	{1,1,0,0,-2,0,0,-1,-1}		//up
};

int windx[4][9] = {
	{1,1,0,0,-2,0,0,-1,-1},		//left
	{-1,1,-2,2,0,-1,1,-1,1},	//down
	{-1,-1,0,0,2,0,0,1,1},		//right
	{1,-1,2,-2,0,1,-1,1,-1}		//up
};

int rate[9] = { 1,1,2,2,5,7,7,10,10 };

int wind(int midy, int midx, int dir) {
	int ret = 0;
	int sand = a[midy][midx];
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		int ny = midy + windy[dir][i];
		int nx = midx + windx[dir][i];
		int wind_sand = (sand * rate[i]) / 100;
		sum += wind_sand;
		if (ny < 0 or ny >= n or nx < 0 or nx >= n) { //틀을 벗어난 경우
			ret += wind_sand;
			continue;
		}
		a[ny][nx] += wind_sand;
	}
	//a자리에 남게 될 모래의 양 계산
	int ny = midy + dy[dir];
	int nx = midx + dx[dir];
	int l = (sand - sum);
	if (ny < 0 or ny >= n or nx < 0 or nx >= n) {
		ret += l;
	}
	else {
		a[ny][nx] += l;
	}
	a[midy][midx] = 0;

	return ret;
}

int solution(int midy, int midx) {
	int ret = 0;
	bool visit[499][499] = { false, };
	int dir = -1;

	while (midy != 0 or midx != 0) {
		visit[midy][midx] = true;
		int nd = (dir + 1) % 4;
		int ny = midy + dy[nd];
		int nx = midx + dx[nd];
		if (visit[ny][nx] == true) {
			nd = dir;
			ny = midy + dy[nd];
			nx = midx + dx[nd];
		}
		ret += wind(ny, nx, nd);
		midy = ny, midx = nx; dir = nd;
	}

	return ret;
}
int main() {

	cin >> n;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> a[y][x];
		}
	}

	int midy = n / 2;
	int midx = n / 2;
	int ret = solution(midy, midx);
	cout << ret << "\n";

}