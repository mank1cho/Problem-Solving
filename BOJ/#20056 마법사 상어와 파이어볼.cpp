#include <cstdio>
#include <vector>
using namespace std;

struct BALL {
	int x, y, m, s, d;	//좌표, 질량, 속도, 방향
};

int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

int main() {
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);

	vector<int> map[50][50];	//맵에 위치하는 공의 인덱스를 저장할 벡터
	vector<BALL> v;		//초기값으로 주어지는 공의 정보를 저장할 벡터
	for (int i = 0; i < M; i++) {
		int x, y, m, s, d;
		scanf("%d%d%d%d%d", &x, &y, &m, &s, &d);
		x--; y--;
		v.push_back({ x,y,m,s,d });
	}
	
	//K시간 동안 실행
	while (K--) {
		//1번째 순회
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].x + dx[v[i].d] * v[i].s;
			int y = v[i].y + dy[v[i].d] * v[i].s;

			//위치 계산입니다. 속도가 맵의 크기보다 클 수 있다는 것에 주의하여 계산해주어야 합니다.
			x = ((x % N) + N) % N;
			y = ((y % N) + N) % N;
			map[x][y].push_back(i);	//현재 공의 인덱스를 맵에 push해줍니다.
			v[i].x = x; v[i].y = y;
		}

		vector<BALL> temp;	//남아있는 공을 잠시 저장할 임시 배열
		//2번째 순회
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].x, y = v[i].y;
			if (map[x][y].empty()) continue;	//비어있는 곳은 이미 소멸된 곳입니다.
			if (map[x][y].size() > 1) {			//사이즈가 2인 곳은 2개 이상의 볼이 위치해 있는 곳입니다.
				//충돌 처리를 해줍니다.
				int m = 0, s = 0, d = v[map[x][y][0]].d % 2;	//질량, 속도, 방향
				int nd = 0;		//새로운 방향

				// 현 위치에는 공들의 인덱스가 담겨있습니다. 질량과 속도의 합을 구해줍니다.
				for (int j = 0; j < map[x][y].size(); j++) {
					int now = map[x][y][j];
					m += v[now].m;
					s += v[now].s;
					if (d != v[now].d % 2) nd = 1;	//만약 방향이 하나라도 다르다면 1
				}

				m /= 5;		//총 질량은 5로 나눕니다.
				s /= map[x][y].size();	//총 속도는 공의 갯수로 나눕니다.

				if (m) {	//질량이 0 이 아닐때만 새롭게 생성된 공을 넣어줍니다. 
					for (int j = 0; j < 4; j++) {	//총 4개가 생성됩니다.
						temp.push_back({ x, y, m, s, nd });
						nd += 2;	//총 4방향입니다.
					}
				}

			}
			else temp.push_back(v[i]);	//만약 사이즈가 1이라면 혼자 있는 공이므로 다시 벡터에 넣어줍니다.
			
			map[x][y].clear();			//한번 확인한 곳은 clear 해줍니다.
		}

		v = temp;	//임시 벡터에는 살아남은 공, 새로 생성된 공들의 정보가 모두 담겨있습니다. v로 옮겨줍니다.
	}

	int ans = 0;
	//남아있는 공의 모든 질량의 합
	for (int i = 0; i < v.size(); i++)
		ans += v[i].m;

	printf("%d", ans);
}