#include <iostream>
#include <algorithm>

using namespace std;

long long dp[300002];
long long s[121];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;

	int idx = 0;
	for (int i = 1;;++i)
	{
		int num = i * (i + 1) * (i + 2) / 6;
		if (num > n)
			break;
		s[idx++] = num;
	}

	fill(dp, dp + 300001, 1e9);
	for (int i = 0; i < idx; ++i)
		dp[s[i]] = 1;

	for (int i = 0; i < idx; ++i)
		for (int j = s[i]; j <= n; ++j)
			dp[j] = min(dp[j], dp[j-s[i]] + 1);

	cout << dp[n];
	return (0);
}