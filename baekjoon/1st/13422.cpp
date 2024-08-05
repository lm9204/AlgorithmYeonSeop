#include <iostream>

using namespace std;

int t;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int n, m, k;
		cin >> n >> m >> k;

		int	arr[100005];
		int sum = 0;

		for (int i = 0; i < n; ++i)
		{
			int val;
			cin >> val;
			arr[i] = val;
		}

		for (int i = 0; i < m; ++i)
			sum += arr[i];

		int ans = 0;
		if (n == m)
			if (sum < k)
				ans++;
		if (n != m)
		{
			for (int i = m; i < n + m; ++i)
			{
				if (sum < k)
					ans++;
				sum += arr[i % n] - arr[(i - m) % n];
			}
		}
		cout << ans << endl;
	}
}