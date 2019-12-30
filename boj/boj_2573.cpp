#include<iostream>
#include<queue>
#include<string.h>

using namespace std;
int N, M;
int cnt2;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int result = 0;
int graph[301][301] = { 0, };
int visit[301][301] = { 0, };
queue <pair<int,int>> q;
queue <pair<int, int>> temp;
queue <pair<int, int>> temp2;
void BFS(int x, int y) {
	temp.push(make_pair(x,y));
	visit[x][y] = 1;
	while (!temp.empty()) {
		x = temp.front().first;
		y = temp.front().second;
		temp.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (graph[nx][ny] > 0 && visit[nx][ny] == 0) {
					visit[nx][ny] = 1;
					temp.push(make_pair(nx, ny));
				}
			}
		}
	}
}

bool CHECK() {
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] > 0 && visit[i][j] == 0) {
				BFS(i, j);
				cnt++;
			}
		}
	}
	memset(visit,0, sizeof(visit));
	if (cnt >= 2) {
		cnt2++;
		return true;
	}
	else
		return false;
}
void MELT() {
	while (!q.empty()) {
		int num = q.size();
		for (int l = 0; l < num; l++) {
			int x = q.front().first;
			int y = q.front().second;
			//q.push(make_pair(x, y));
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < N && 0 <= ny && ny < M) {
					if (graph[nx][ny] == 0) {
						if (graph[x][y] > 0) {
							temp2.push(make_pair(x, y));
							/*
							graph[x][y] -= 1;
							if (graph[x][y] > 0) {
								q.push(make_pair(x, y));
							}
							*/
						}
					}
				}
			}
		}
		while(!temp2.empty()) {
			int tx = temp2.front().first;
			int ty = temp2.front().second;
			temp2.pop();
			if (graph[tx][ty] > 0) {
				graph[tx][ty] -= 1;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[i][j] > 0) {
					q.push(make_pair(i, j));
				}
			}
		}/*
		cout << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout<< graph[i][j]<< " ";
			}
			cout << endl;
		}*/
		//cout<<endl;
		result++;
		if (CHECK())
			break;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] > 0) {
				q.push(make_pair(i, j));
			}
		}
	}
	MELT();
	if (cnt2 == 0)
		result = 0;
	cout << result << endl;

	return 0;
}