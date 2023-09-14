#include<iostream>
#include<vector>
using namespace std;

struct Fireball {
	int y, x;
	int m, s, d;
};

const int dy[8] = { -1,-1,0,1,1,1,0,-1 };
const int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

int n, m, k;
vector<Fireball> ball;
vector<int> map[50][50];

void move() {
	vector<int> new_map[50][50];
	for (int i = 0; i < ball.size(); i++) {
		int dir = ball[i].d;
		int speed = ball[i].s % n;
		int ny = (ball[i].y + (dy[dir] * speed) + n) % n; //방향이 마이너스가 될 경우를 생각해서 n을 더해서
		int nx = (ball[i].x + (dx[dir] * speed) + n) % n; //나머지 값 위치를 구해줌
		new_map[ny][nx].push_back(i);
		ball[i].y = ny;
		ball[i].x = nx;
	}
	
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			map[y][x] = new_map[y][x];
		}
	}
}
void sum() {
	vector<Fireball> new_ball;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x].size() == 0) {
				continue;
			}
			if (map[y][x].size() == 1) {
				int index = map[y][x][0];
				new_ball.push_back(ball[index]);
				continue;
			}
			int sum_m = 0, sum_s = 0;
			bool odd = true, even = true;
			for (int i = 0; i < map[y][x].size(); i++) {
				int index = map[y][x][i];
				sum_m += ball[index].m;
				sum_s += ball[index].s;
				if (ball[index].d % 2 == 0) {
					odd = false;
				}
				else {
					even = false;
				}
			}
			if (sum_m / 5 == 0) {
				continue;
			}
			int cur_m = sum_m / 5;
			int cur_s = sum_s / map[y][x].size();
			for (int i = 0; i < 4; i++) {
				if (odd or even) { //모두 홀수이거나 짝수일 때
					new_ball.push_back({ y,x,cur_m,cur_s,i * 2 });
				}
				else {
					new_ball.push_back({ y,x,cur_m,cur_s,i * 2 + 1 });
				}
			}
		}
	}
	ball = new_ball;
}
int solve() {
	//k번 실행
	while (k--) {
		move();
		sum();
	}

	int ret = 0;
	//남은 파이어볼의 질량 더하기
	for (int i = 0; i < ball.size(); i++) {
		ret += ball[i].m;
	}
	return ret;
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int y, x, m, s, d;
		cin >> y >> x >> m >> s >> d;
		--y; --x;
		ball.push_back({ y,x,m,s,d }); //파이어볼 정보 저장
		map[y][x].push_back(i); //해당 배열에 있는 파이어볼 인덱스
	}
	int ret = solve();
	cout << ret;

	return 0;
}