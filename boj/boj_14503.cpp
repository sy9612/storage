#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
queue<pair<int, int>> q;
int graph[51][51] = { 0, };
int visit[51][51] = { 0, };
int N, M;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int cnt = 0;
void FIRST(int x, int y, int d);
int SECOND(int x, int y, int d) {

	int cnt2 = 0, cnt1 = 0;
	int bx, by;
	int nx, ny;
	int td;
	switch (d) {
	case 0:
		nx = x + dx[1];
		ny = y + dy[1];
		bx = x + 1;
		by = y;
		td = 3;
		break;
	case 1:
		nx = x + dx[0];
		ny = y + dy[0];
		bx = x;
		by = y - 1;
		td = 0;
		break;
	case 2:
		nx = x + dx[3];
		ny = y + dy[3];
		bx = x - 1;
		by = y;
		td = 1;
		break;
	case 3:
		nx = x + dx[2];
		ny = y + dy[2];
		bx = x;
		by = y + 1;
		td = 2;
		break;
	}
	
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];

		if (graph[tx][ty] != 0)
			cnt2++;
	}
	if (cnt2 == 4) {
		cnt2 = 0;
		if (graph[bx][by] == 1) {
			cout << cnt << endl;
			return 0;
		}
		else {
			SECOND(bx, by, d);
		}
	}
	cnt2 = 0;
	if (graph[nx][ny] == 0) {//2-a
		FIRST(nx, ny, td);
	}
	else{
		SECOND(x, y, td);
	}

}
void FIRST(int x, int y, int d) {
	/*q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();*/
		//현재 위치 청소
	if (graph[x][y] == 0) {
		graph[x][y] = 2;
		cnt++;
	}
	/*
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout<< graph[i][j]<<" ";
		}
		cout << endl;
	}
	*/
	SECOND(x, y, d);

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
	FIRST(r,c,d);
	cout << cnt << endl;
	return 0;
}