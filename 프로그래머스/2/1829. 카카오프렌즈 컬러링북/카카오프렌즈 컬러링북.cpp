#include <vector>

using namespace std;

vector<vector<int>> pic;
vector<vector<int>> visit;
vector<int> dx;
vector<int> dy;
int max_x;
int max_y;
int cnt;

int dfs(int x, int y) {
	visit[x][y] = 1;
	for (int i= 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_y >= 0 && next_x < max_x && next_y < max_y && pic[next_x][next_y]==pic[x][y] && visit[next_x][next_y]!=1) {		
			cnt++;
			dfs(next_x, next_y);
		}
	}
	return cnt;
}


vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;


	pic = picture;
	dx = { 0, 1, 0, -1};
	dy = { 1, 0, -1, 0 };
	max_x = m;
	max_y = n;
	vector<vector<int>> v(m, vector<int>(n, 0));
	visit = v;
	for (int i = 0; i < pic.size();i++) {

		for (int j = 0; j < pic[0].size(); j++) {

			if (visit[i][j] == 0 && pic[i][j]!=0) {
				cnt = 1;
				max_size_of_one_area = max(dfs(i, j), max_size_of_one_area);
				number_of_area++;
			}
		}
	}
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}