#include<iostream>
#include<map>
using namespace std;

int main() {
	map <int, int> m;
	int n;
	int i;
	int temp1, temp2;
	cin >> n;
	temp2 = 1;
	for (i = 0; i < n; i++) {
		cin >> temp1;
		m.insert(make_pair(temp1, temp2));
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->first << endl;
	}

}