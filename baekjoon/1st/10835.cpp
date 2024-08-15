#include <iostream>
#include <algorithm>

using namespace std;

int dp[2005][2005];
int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int left[2005];
	int right[2005];

	cin >> n;
	for (int i = n; i > 0; --i) cin >> left[i];
	for (int i = n; i > 0; --i) cin >> right[i];

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
			if (left[i] > right[j])
				dp[i][j] = max(dp[i][j], dp[i][j - 1] + right[j]);
		}
	}
	cout << dp[n][n];
	return (0);
}