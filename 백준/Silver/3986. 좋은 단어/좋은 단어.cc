#include<iostream>
#include<stack>
using namespace std;
int ans=0;
void solution(string s) {
	stack<char> st;
	for (int i = 0; i < s.length(); i++) {
		if(st.empty()) st.push(s[i]);
		else {
			if (st.top() == s[i]) st.pop();
			else {
				st.push(s[i]);
			}
		}
	}
	if (st.empty()) ans++;

	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		
		solution(s);
	}

	cout << ans << "\n";
}