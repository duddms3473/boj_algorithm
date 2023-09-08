#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m, sw = 0;
    vector<int> vec;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    //정렬
    for (int i = n - 1; i >= 0; i--) {
        int tmp, ind, max = 0;
        for (int j = 0; j <= i; j++) {
            if (vec[j] > max) {
                max = vec[j];
                ind = j;
            }
        }
        //swap 안 할 경우
        if (ind == i) continue;

        //swap
        tmp = vec[ind];
        vec[ind] = vec[i];
        vec[i] = tmp;
        sw++;
        //swap 횟수가 m일 경우
        if (sw == m) {
            break;
        }
    }
    if (sw < m) {
        cout << -1 << "\n";
        return 0;
    }
    for (auto i : vec) {
        cout << i << " ";
    }
    return 0;
}