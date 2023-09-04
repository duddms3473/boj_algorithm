#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
int conv, x, y, dx, dy;
vector<pair<int,int>> vec;
bool visit[100];
bool solution() {
	queue<pair<int, int>> q;

	q.push({ x, y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (abs(x-dx)+abs(y-dy)<=1000) {
			return true;
		}

		for (int i = 0; i < conv; i++) {
			if (visit[i] == true) continue;
			int xx, yy;
			xx = vec[i].first;
			yy = vec[i].second;

			if (abs(x - xx) + abs(y - yy) <= 1000) {
				visit[i] = true;
				q.push(vec[i]);
			}

		}

	}

	return false;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> conv;
		cin >> x >> y;
		for (int j = 0; j < conv; j++) {
			int a, b;
			cin >> a >> b;
			vec.push_back({ a, b });
		}
		cin >> dx >> dy;
		memset(visit, 0, sizeof(visit));
		
		if (!solution()) {
			cout << "sad\n";
		}
		else {
			cout << "happy\n";
		}

		vec.clear();
	}

	
	return 0;
}