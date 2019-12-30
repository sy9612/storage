#include<iostream>
#include<queue>
int arr[100001] = { 0, };
int visit[100001] = { 0, };

using namespace std;
int n, k;
int cnt = 0;

int main() {
	queue <int> q;
	cin >> n >> k;
	q.push(n);
	arr[n] = 1;

	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		if (temp == k)
			break;
		if (0 <= (temp - 1)) {
			if (arr[temp - 1] == 0) {
				arr[temp - 1] = arr[temp] + 1;
				q.push(temp - 1);
			}
		}
		if ((temp + 1) <= 100000) {
			if (arr[temp + 1] == 0) {
				arr[temp + 1] = arr[temp] + 1;
				q.push(temp + 1);
			}
		}
		if ((temp * 2) <= 100000) {
			if (arr[temp * 2] == 0) {
				arr[temp * 2] = arr[temp] + 1;
				q.push(temp * 2);
			}
		}
	}
	cout << arr[k] - 1 << endl;
	return 0;
}