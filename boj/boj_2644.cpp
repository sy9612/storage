#include<iostream>
#include<queue>
using namespace std;
int per1, per2;
int n, m;
int graph[101][101] = { 0, };
int visit[101] = { 0, };
void BFS(int per) {
	int cnt = 0;
	int temp;
	queue<int> q;
	q.push(per);
	//visit[per] = 1;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (visit[i
			] == 0 && graph[temp][i] == 1) {
				q.push(i);
				visit[i] = visit[temp] + 1;
			}
		}

	}

}
int main() {
	int x, y;

	cin >> n;
	cin >> per1 >> per2;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x][y] = graph[y][x] = 1;
	}

	BFS(per1);
	if (visit[per2] == 0)
		cout << -1 << endl;
	else
		cout << visit[per2] << endl;

	return 0;
}