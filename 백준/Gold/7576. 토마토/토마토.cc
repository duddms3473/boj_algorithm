#include<iostream>
#include<queue>
using namespace std;

struct tomato {
    int x, y;
};

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
    ios::sync_with_stdio(false); 
    int m, n, max = 0;
    cin >> n >> m;
    int arr[1001][1001];
    queue<tomato> que;
    
//입력받으며 익은 토마토인 경우 큐에 넣어줌
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                tomato tmp;
                tmp.x = i;
                tmp.y = j;
                que.push(tmp);
            }

        }
    }

  //일종의 BFS..
    while (!que.empty()) {
        tomato t;
        int tx, ty, xx, yy;
        t = que.front();
        que.pop();
        tx = t.x;
        ty = t.y;

        for (int i = 0; i < 4; i++) {
            xx = tx + dx[i];
            yy = ty + dy[i];

            if (xx >= 0 and xx <m and yy >= 0 and yy <n and arr[xx][yy] == 0) {
                tomato tmp;
                tmp.x = xx; tmp.y = yy;
                que.push(tmp);
                arr[xx][yy] = arr[tx][ty]+1;
            }
        }
    }
    
//익지않은 토마토 있는지 확인 후 며칠 필요한 지 출력
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0) {
                cout << -1 << endl;
                return 0;
            }
            if (max < arr[i][j]) max = arr[i][j];
        }
    }
    cout << max-1 << endl;
}