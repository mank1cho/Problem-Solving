//2020.11.09 조만기
//https://www.acmicpc.net/problem/10942

#include <iostream>
using namespace std;

bool dp[2000][2000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, arr[2000];

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		dp[i][i] = true;	//값이 1개인 경우는 팰린드롬이 성립한다.
		
		if (i && arr[i - 1] == arr[i]) {
			dp[i - 1][i] = true;	//왼쪽과 오른쪽 수가 같다면 팰린드롬이 성립한다.
		}

	}

	// O(n^2) 의 시간복잡도로 팰린드롬 여부를 확인할 수 있다.
	for (int k = 2; k < N; ++k) {
		for (int left = 0; left <= N - k; ++left) {
			int right = left + k;

			//(만약 현재 선택한 왼쪽값과 오른쪽 값이 같고) && (그 사이가 이미 팰린드롬이라면) 팰린드롬이 성립한다.
			if (arr[left] == arr[right] && dp[left + 1][right - 1]) {
				dp[left][right] = true;
			}

		}
	}

	int M;
	cin >> M;
	while (M--) {
		int left, right;
		cin >> left >> right;
		cout << dp[left-1][right-1] << '\n';	//선택한 부분이 팰린드롬인지 출력한다.
	}

	return 0;
}