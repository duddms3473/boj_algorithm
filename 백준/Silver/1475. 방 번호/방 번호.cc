#include<iostream>
#include<string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	int max=0;
	int arr[10] = { 0, };
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		arr[s[i]-48]++;
	}
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] > max and i!=6 and i!=9) max = arr[i];
	}
	if (((arr[6] + arr[9]) / 2 + (arr[6] + arr[9]) % 2) > max)max = (arr[6] + arr[9]) / 2 + (arr[6] + arr[9]) % 2;

	cout<<max<<"\n";

	return 0;
}