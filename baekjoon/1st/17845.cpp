#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int dp[10001];
int I[1001], T[1001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= k; ++i)
		cin >> I[i] >> T[i];

	for (int i = 1; i <= k; ++i)
		for (int j = n; j >= T[i]; --j)
			dp[j] = max(dp[j], dp[j-T[i]] + I[i]);

	cout << dp[n];
	return (0);
}