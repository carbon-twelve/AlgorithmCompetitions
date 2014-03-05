#include <iostream>
#include <string>
#include <vector>

namespace lake_counting {
	using namespace std;
	int N, M;
	vector<vector<char>> field;

	void Dfs(int x, int y) {
		field[x][y] = '.';

		for (int dx = -1; dx <= 1; ++dx) {
			for (int dy = -1; dy <= 1; ++dy) {
				int nx = x + dx, ny = y + dy;
				if (0 <= nx && nx < N && 0 <= ny && ny <= M && field[nx][ny] == 'W') {
					Dfs(nx, ny);
				}
			}
		}
		return;
	}

	void Solve() {
		int res = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (field[i][j] == 'W') {
					Dfs(i, j);
					++res;
				}
			}
		}
		cout << res << endl;
	}
}