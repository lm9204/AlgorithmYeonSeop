#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int dp[10005];
pair<int, int> candies[5005];
int n, c;
double m, p;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
			break;
		memset(dp, 0, sizeof(dp));

		for (int i = 0; i < n; ++i)
		{
			cin >> c >> p;
			candies[i] = {c, (int)(p * 100 + 0.5)};
		}

		int intM = (int)(m * 100 + 0.5);
		for (int i = 0; i < n; ++i)
			for (int j = candies[i].second; j <= intM; ++j)
				dp[j] = max(dp[j], dp[j - candies[i].second] + candies[i].first);

		cout << dp[intM] << "\n";
	}
	return (0);
}