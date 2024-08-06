#include <iostream>
#include <vector>

using namespace std;

int subjects[1005];
vector<int> pre[1005]; 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	int left, right;
	for (int i = 0; i < m; ++i)
	{
		cin >> left >> right;
		pre[right].push_back(left);
	}

	for (int i = 1; i <= n; ++i)
	{
		for (vector<int>::iterator it = pre[i].begin(); it != pre[i].end(); ++it)
		{
			subjects[i] = max(subjects[i], subjects[*it] + 1);
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << subjects[i] + 1 << " ";
	return (0);
}