#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> result;

int graph[26][26] = { 0, };
int visit[26][26] = { 0, };
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n;
void BFS(int x, int y) {
	int nx, ny;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	int cnt = 0;
	
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		visit[x][y] = 1;
		cnt++;
		q.pop();

		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (visit[nx][ny] == 0 && graph[nx][ny] == 1) {
					q.push(make_pair(nx, ny));
					visit[nx][ny] = 1;
					//cnt++;

				}
			}
		}
	}
	//cout << cnt << endl;
	result.push_back(cnt);
}
int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == 0 && graph[i][j] == 1)
				BFS(i,j);
		}
	}
	cout << result.size() << endl;
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i]<< endl;
	}

	return 0;
}