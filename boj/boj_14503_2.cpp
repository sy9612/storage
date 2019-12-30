#include<iostream>
#include<queue>
using namespace std;
queue<pair<pair<int, int>, int>> q;
int graph[51][51] = { 0, };
int visit[51][51] = { 0, };
int N, M;
int dx[5] = { -1, 0, 1, 0 };
int dy[5] = { 0, 1, 0, -1 };
int cnt = 0;
void BFS(int x, int y, int d) {
	q.push(make_pair(make_pair(x, y),d));
	//visit[x][y] = 1;

	while (!q.empty()) {
		int nx, ny, nd;
		x = q.front().first.first;
		y = q.front().first.second;
		d = q.front().second;
		q.pop();
		int temp = 0;


		if (graph[x][y] == 0) {
			graph[x][y] = 2;
			cnt++;
			/*
			cout << endl;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					cout << graph[i][j] << " ";
				}
				cout << endl;
			}
			*/
		}
		nd = d;
		for (int i = 0; i < 4; i++) {
			if (nd == 0)
				nd = nd + 4;
			else
				nd = nd;
			nd = nd - 1;
			nx = x + dx[nd];
			ny = y + dy[nd];
			if (graph[nx][ny] == 0) {
				q.push(make_pair(make_pair(nx, ny), nd));
				break;
			}
			else {
				temp++;
			}
		}
		if (temp == 4) {
			temp = 0;
			nd = d - 2;
			if (nd < 0)
				nd += 4;
			nx = x + dx[nd];
			ny = y + dy[nd];
			if (graph[nx][ny] == 1)
				break;
			else
				q.push(make_pair(make_pair(nx, ny), d));
		}
	}


}
int main() {
	int r, c, d;
	cin >> N >> M;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}
	
	BFS(r, c, d);
	cout << cnt << endl;
	return 0;
}
