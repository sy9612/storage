#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<string.h>

using namespace std;
int n;
int mini = 100;
int maxi = 1;
int result = 1;
int graph[101][101] = { 0, };
int visit[101][101] = { 0, };
int cnt = 0;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
map <int, int> m;
queue <pair<int, int>> q;

void BFS(int x, int y, int t) {
	q.push(make_pair(x, y));
	visit[x][y] = 1;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		int nx, ny;
		q.pop();

		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (visit[nx][ny] == 0 && t < graph[nx][ny]) {
					q.push(make_pair(nx, ny));
					visit[nx][ny] = 1;
				}
			}
		}
	}
	cnt++;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
			m.insert(make_pair(graph[i][j], 0));
		}
	}

	for (auto it = m.begin(); it != m.end(); it++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] == 0 && it->first < graph[i][j]) {
					BFS(i, j, it->first);
				}
			}
		}
		result = max(result, cnt);
		cnt = 0;
		memset(visit, 0, sizeof(visit));

	}

	cout << result << endl;
	return 0;
}