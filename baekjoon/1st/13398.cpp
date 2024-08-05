#include <iostream>
#include <cmath>

using namespace std;

int arr[100005];
int dp[100005][2];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, sum, MIN, MAX;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	MIN = 0, MAX = arr[0];
	dp[0][0] = arr[0];
	dp[0][1] = arr[0];
	for (int i = 1; i < n; ++i)
	{
		dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
		MAX = max(MAX, max(dp[i][0], dp[i][1]));
	}

	cout << MAX;
	return (0);
}