#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
int graph[1001][1001] = { {0,}, };
int bfs[1001] = { 0, };
int dfs[1001] = { 0, };
vector<int> vs;
int n, m, v;
void BFS(int v) {
	queue<int> qu;
	qu.push(v);
	bfs[v] = 1;
 	while (!qu.empty()) {
		int temp = qu.front();
		cout << temp << " ";
		
		qu.pop();
		for (int i = 1; i <= n; i++) {
			if (graph[temp][i] == 1 && bfs[i] == 0) {
				qu.push(i);
				bfs[i] = 1;
			}

		}
	}
}
void DFS(int v) {
	int i, j;
	cout << v << " ";
	dfs[v] = 1;
	for (i = 1; i <= n; i++) {
		if (graph[v][i] == 1 && dfs[i] == 0)
			DFS(i);
	}	
}
int main() {
	int a, b;
	int i;
	
	cin >> n >> m >> v;
	
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	DFS(v);
	cout << endl;
	BFS(v);
	return 0;
}