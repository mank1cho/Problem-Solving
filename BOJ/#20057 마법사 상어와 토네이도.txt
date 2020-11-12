#include <cstdio>

int dx[4] = { 0,1,0,-1 };	//왼,아,오,위
int dy[4] = { -1,0,1,0 };

int wind[10][3] = {  //총 10방향으로 흩날림
	{5,0,0},	//비율, 방향1, 방향2
	{2,3,3},
	{2,1,1},
	{1,2,3},
	{1,2,1},
	{10,0,3},
	{10,0,1},
	{7,3,0}, //7%인 곳은 방향1만 이동시킬것
	{7,1,0},
	{7,0,0}	//마지막은 '알파'자리. 55%로 하면 안됩니다..
};

int main() {
	int N, map[500][500];
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);

	int x = N / 2, y = N / 2, dis = 2, dir = 0, ans = 0;

	while (x || y) {	// (0,0) 일 때까지 진행.

		for (int i = 0; i < dis / 2; i++) {		//1칸,1칸,2칸,2칸.. 이런식으로 진행되니까..
			x += dx[dir]; y += dy[dir];		//현재 토네이도 위치
			int now = map[x][y];			//현재 토네이도 위치에 있는 모래
			int sum = 0;					//바람에 날릴 모래들

			for (int j = 0; j < 10; j++) {	//총 10방향으로 날림
				int nd1 = (dir + wind[j][1]) % 4;
				int nd2 = (dir + wind[j][2]) % 4;
				int nx = x + dx[nd1] + dx[nd2];
				int ny = y + dy[nd1] + dy[nd2];
				if (wind[j][0] == 7) nx -= dx[nd2], ny -= dy[nd2];	// 7%는 한칸만 이동하는 곳.

				int sand = now * wind[j][0] / 100;	//흩날릴 모래

				if (j == 9) sand = now - sum;	//9는.. 알파 자리
				else sum += sand;			//나머지는 흩날린 모래

				if (nx < 0 || ny < 0 || nx >= N || ny >= N) ans += sand;	//맵 밖으로 나간 모래
				else map[nx][ny] += sand;		//맵 밖으로 나가지 않은 모래
			}

			map[x][y] = 0;	//토네이도가 떠난 자리엔 모래가 없음.
			if (!x && !y) break;	// (0,0)에 도달했으면 break.
		}

		++dis;
		if (++dir == 4) dir = 0;
	}
	printf("%d", ans);
}