#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n, m;
int graph[101][101] = { 0, };
int visit[101][101] = { 0, };
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[x][y] = 1;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0<=nx && nx<n && 0 <= ny && ny < m) {
				if (visit[nx][ny] == 0 && graph[nx][ny] == 1) {
					q.push(make_pair(nx, ny));
					visit[nx][ny] = visit[x][y] + 1;
				}
				/*else if (visit[nx][ny] == 0) {
					visit[nx][ny] = -1;
				}*/
			}
		}
	}
}

int main() {
	int i, j;

	cin >> n >> m;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}

	bfs(0,0);
	cout << graph[n - 1][m - 1]<<endl;
	return 0;
}