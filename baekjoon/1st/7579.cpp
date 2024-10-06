#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int dp[10001];
int app[101];
int cost[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> app[i];

	for (int i = 1; i <= n; ++i)
		cin >> cost[i];

	int totalzero = 0;
	for (int i = 1; i <= n; ++i)
		if (cost[i] == 0)
			totalzero += app[i];

	dp[0] = totalzero;

	for (int i = 1; i <= n; ++i)
		if (cost[i] > 0)
			for (int j = 10000; j >= cost[i]; --j)
				dp[j] = max(dp[j], dp[j - cost[i]] + app[i]);

	int ans = 0;

	while (dp[ans] < m) ans++;
	cout << ans;
	return (0);
}