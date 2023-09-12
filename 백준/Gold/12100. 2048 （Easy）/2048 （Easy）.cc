#include<iostream>

using namespace std;
int n,ret=0;
struct board {
	int map[20][20];

	void rotate() {
		int temp[20][20];

		//rotate 해서 temp에 저장
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				temp[i][j] = map[n - j - 1][i];
			}
		}
		//rotate완료된 temp배열을 기존 배열에 저장
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = temp[i][j];
			}
		}
	}
		//해당 배열에서 가장 큰 값 구하기
	int get_max() {
		int ret = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (ret < map[i][j]) {
					ret = map[i][j];
				}
			}
		}
		return ret;
	}
	
	void up() {
		int temp[20][20];

		for (int j = 0; j < n; j++){
			bool flag = false;
			int target = -1; //target은 현재 숫자를 놓아야 할 위치
			
			for (int i = 0; i < n; i++) {
				if (map[i][j] == 0) continue;

				if (flag==true and map[i][j] == temp[target][j]) { //값이 같은 경우
					temp[target][j] *= 2;
					flag = false;

				}
				else { //다른 경우
					target++;
					temp[target][j] = map[i][j];
					flag = true;
				}
			}
			target++;
			while(target<n) { //나머지 빈 공간 0으로 채워줌
				temp[target][j] = 0;
				target++;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = temp[i][j];
			}
		}
	}
	
};

void dfs(board cur, int count) {
	if (count == 5) {
		int candi = cur.get_max();
		if (ret < candi) {
			ret = candi;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		board next = cur; //board를 계속 선언하며 dfs를 이용해 최대 값 구함
		next.up();
		dfs(next, count + 1);
		cur.rotate();

	}
}
int main() {
	board b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> b.map[i][j];
		}
	}
	
	dfs(b, 0);

	cout << ret << "\n";

	return 0;
}