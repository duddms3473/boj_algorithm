#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
vector<pair<int, int>> vec[10001];
bool visit[10001];
int n, m, s, f, mid,low=1, high=0;

bool bfs(int cost) {
    queue<int> que;
    bool visit[10001] = { false, };
    visit[s] = true;
    que.push(s);
    
    while (!que.empty()) {
        int tmp = que.front();
        
        que.pop();
        if (tmp == f) {
            return true;
        }

        for (int i = 0; i < vec[tmp].size(); i++) {
            int next = vec[tmp][i].first;
            int kg = vec[tmp][i].second;
            

            if (kg < cost) {
                continue;
            }
            else {
                if (visit[next] == false) {
                    que.push(next);
                    visit[next] = true;
                }
            }
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        vec[a].push_back({ b,c });
        vec[b].push_back({ a,c });
        high = max(high, c);
    }
    cin >> s >> f;
    //이분탐색
    while (low <= high) {
        mid = (low + high) / 2;

        if (bfs(mid)) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }


    cout << high << "\n";

    return 0;
}