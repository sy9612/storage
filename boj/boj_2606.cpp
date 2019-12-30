#include<iostream>
#include<queue>

using namespace std;
int graph[101][101] = { 0, };
int visit[101] = { 0, };
int n, m;
void BFS(int num) {
	int cnt = 0;
	queue<int> q;
	q.push(num);

	while (!q.empty()) {
		num = q.front();
		q.pop();
		if (visit[num] == 0) {
			visit[num] = 1;
			cnt++;
			for (int i = 1; i <= n; i++) {
				if (graph[num][i] == 1 && visit[i] == 0) {
					q.push(i);
				}
			}
		}

	}
	cout << cnt-1 << endl;
}
int main() {
	int x, y;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	BFS(1);
	return 0;
}