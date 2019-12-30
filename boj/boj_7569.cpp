#include<iostream>
#include<queue>
using namespace std;
int m, n, h;
int toma[101][101][101] = { 0, };
int dx[] = {0,0,1,0,0,-1};
int dy[] = {0,1,0,0,-1,0};
int dz[] = {1,0,0,-1,0,0};
int cnt = 0;
queue <pair<pair<int, int>, int>> q;

bool check_toma() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (toma[k][j][i] == 0)
					return false;
			}
		}
	}
	return true;
}
void BFS() {
	int x, y, z;
	int nx, ny, nz;
	int i, j;
	while (!q.empty()) {
		int cur_q = q.size();
		cnt++;
		for (j = 0; j < cur_q; j++) {
			x = q.front().first.first;
			y = q.front().first.second;
			z = q.front().second;
			q.pop();

			////////6면 토마토 익히기////////
			for (i = 0; i < 6; i++) {
				nx = x + dx[i];
				ny = y + dy[i];
				nz = z + dz[i];
				if (0 <= nx && nx < m && 0 <= ny && ny < n && 0 <= nz && nz < h) {
					if (toma[nx][ny][nz] == 0) {
						toma[nx][ny][nz] = 1;
						q.push(make_pair(make_pair(nx, ny), nz));
					}
				}
			}
			////////////////////////////////
		}
	}

}
int main() {

	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> toma[k][j][i];
				if (toma[k][j][i] == 1) {
					q.push(make_pair(make_pair(k, j), i));
				}
			}
		}
	}
	if (check_toma())
		cout << 0 << endl;
	else {
		BFS();
		if (!check_toma())
			cout << -1 << endl;
		else
			cout << cnt-1 << endl;
	}
	return 0;
}