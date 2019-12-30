#include<iostream>
#include<queue>
using namespace std;
int F, S, G, U, D;
int visit[1000001] = { 0, };
queue <int> q;

int main() {
	cin >> F >> S >> G >> U >> D;
	q.push(S);
	visit[S] = 1;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		if (temp == G)
			break;

		if (1<=(temp - D)) {
			if (visit[temp - D] == 0) {
				q.push(temp - D);
				visit[temp - D] = visit[temp] + 1;
			}
		}
		if ((temp + U) <= F) {
			if (visit[temp + U] == 0) {
				q.push(temp + U);
				visit[temp + U] = visit[temp] + 1;
			}
		}


	}


	if (visit[G] == 0) {
		cout << "use the stairs" << endl;
	}
	else {
		cout << visit[G] - 1 << endl;
	}
	return 0;
}