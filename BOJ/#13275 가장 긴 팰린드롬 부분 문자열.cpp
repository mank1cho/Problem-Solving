//2020.11.09 조만기
//https://www.acmicpc.net/problem/13275

#include <iostream>
#include <algorithm>
using namespace std;

int A[200000];

void manachers(string& s) {
	int size = s.size();
	int r = 0, p = 0;
	for (int i = 0; i < size; ++i) {
		
		if (i <= r) {
			A[i] = min(A[2 * p - i], r - i);
		}
		else {
			A[i] = 0;
		}

		while (i - A[i] - 1 >= 0 && i + A[i] + 1 < size && s[i - A[i] - 1] == s[i + A[i] + 1]) {
			++A[i];
		}

		if (r < i + A[i]) {
			r = i + A[i];
			p = i;
		}

	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string t;
	cin >> t;

	string s = "";
	for (int i = 0; i < t.size(); ++i) {
		s += '#';
		s += t[i];
	}
	s += '#';
	manachers(s);

	int ans = 0;
	for (int i = 0; i < s.size(); ++i) {
		ans = max(ans, A[i]);
	}

	cout << ans;
	return 0;
}