#include <iostream>
#include <vector>
#include <utility>
#include <queue>

namespace maze_shortest_path {
	const int INF = 1000000000;
	const int MAX_N = 100;
	const int MAX_M = 100;

	using namespace std;

	typedef pair<int, int> P;

	int N, M;
	vector<vector<char>> maze;
	int sx, sy;
	int gx, gy;

	int d[MAX_N][MAX_M];
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

	int Bfs() {
		queue<P> bfsQueue;

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				d[i][j] = INF;
			}
		}

		bfsQueue.push(make_pair(sx, sy));
		d[sx][sy] = 0;

		while (!bfsQueue.empty()) {
			P current = bfsQueue.front();
			bfsQueue.pop();
			int x = current.first, y = current.second;
			if (x == gx && y == gy) {
				break;
			}
			for (int i = 0; i < 4; ++i) {
				int nextX = x + dx[i], nextY = y + dy[i];
				if (0 <= nextX && nextX < N && 0 <= nextY && nextY < M && maze[nextX][nextY] != '#' && d[nextX][nextY] == INF) {
					bfsQueue.push(make_pair(x + dx[i], y + dy[i]));
					d[nextX][nextY] = d[x][y] + 1;
				}
			}
		}

		return d[gx][gy];
	}

	void Solve() {
		int res = Bfs();
		cout << res << endl;
	}
}