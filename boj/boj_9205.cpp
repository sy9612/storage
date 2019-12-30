#include<iostream>
#include<queue>
#include<vector>
using namespace std;
bool dist(int x1, int x2,int y1, int y2) {
	return ((abs(x1 - x2) + abs(y1 - y2)) <= 1000 ? true : false);
}
int main() {
	int t, n;
	int x, y;
	int i, j;
	bool result = false;
	cin >> t;
	for (i = 0; i < t; i++) {
		pair<int, int> home;
		vector< pair<int, int>> convi;
		vector< int> visit;
		pair<int, int> fest;
		cin >> n;
		//집
		cin >> x >> y;
		home.first = x;
		home.second = y;
		//편의점
		for (j = 0; j < n; j++) {
			cin >> x >> y;
			convi.push_back(make_pair(x, y));
		}
		visit.resize(n+1, 0);

		//페스티벌
		cin >> x >> y;
		fest.first = x;
		fest.second = y;
		convi.push_back(make_pair(x, y));

		queue< pair<int, int>> q;
		q.push(make_pair(home.first,home.second));
		
		while (!q.empty()) {
			x = q.front().first;
			y = q.front().second;
			q.pop();
			if (x == fest.first && y == fest.second) {
				result = true;
				break;
			}
			
			for (int i = 0; i < n+1; i++) {
				if (dist(x, convi[i].first, y, convi[i].second) == true && visit[i] == 0) {
					q.push(make_pair(convi[i].first, convi[i].second));
					visit[i] = 1;
				}
			}
		}

		cout << (result ? "happy" : "sad") << endl;
		result = false;
	}
	return 0;
}