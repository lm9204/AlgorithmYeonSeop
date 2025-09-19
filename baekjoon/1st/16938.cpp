#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, L, R, X;
vector<int> p;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> L >> R >> X;
	for (int i = 0; i < N; ++i)
	{
		int n; cin >> n;
		p.push_back(n);
	}

	int count = 0, totalSubsets = 1 << N;

	for (int subset = 0; subset < totalSubsets; ++subset)
	{
		vector<int> selected;

		for (int i = 0; i < N; ++i)
			if (subset & (1 << i))
				selected.push_back(p[i]);

		if (selected.size() >= 2)
		{
			int sum = 0, MIN = 1000000, MAX = 0;
			for (int val : selected)
			{
				if (MIN > val)
					MIN = val;
				if (MAX < val)
					MAX = val;
				sum += val;
			}

			if (L <= sum && sum <= R && MAX - MIN >= X)
				++count;
		}
	}

	cout << count;
	return (0);
}