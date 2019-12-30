#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int BinarySearch() {
	return 0;
}
int main()
{
	int n, m;
	int i, j, temp;
	vector<int>A;
	vector<int>B;

	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> temp;
		A.push_back(temp);
	}
	cin >> m;
	for (i = 0; i < m; i++)
	{
		cin >> temp;
		B.push_back(temp);
	}
	sort(A.begin(), A.end());

	for (i = 0; i < m; i++)
	{
		BinarySearch( );
	}

	return 0;
}