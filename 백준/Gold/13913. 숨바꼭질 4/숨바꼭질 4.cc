#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n, k;
queue<pair<int, int>> q;
vector<int> family;
int parent[200001];
bool check[200001];
void bfs() {
    int x, num;

    while (!q.empty()) {
        x = q.front().first;
        num = q.front().second;
        q.pop();

        if (x == k) {//역추적
            int tmp = x;
            cout << num << "\n";
            while (tmp != n) {
                family.push_back(tmp);
                tmp = parent[tmp];
            }
            break;
        }

        if (x - 1 >= 0 and x - 1 <= 200000 and check[x - 1] == false) {
            parent[x - 1] = x;
            check[x - 1] = true;
            q.push({ x - 1,num + 1 });
        }
        if (x + 1 >= 0 and x + 1 <= 200000 and check[x + 1] == false) {
            parent[x + 1] = x;
            check[x + 1] = true;
            q.push({ x + 1,num + 1 });
        }
        if (x * 2 >= 0 and (x * 2) <= 200000 and check[x * 2] == false) {
            parent[x * 2] = x;
            check[x * 2] = true;
            q.push({ x * 2,num + 1 });
        }
    }

    return;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    q.push({ n,0 });
    check[n] = true;
    //bfs
    bfs();
    //뒤에서부터 출력
    cout << n << " ";
    for (int i = family.size() - 1; i >= 0; i--) {
        cout << family[i] << " ";
    }

}