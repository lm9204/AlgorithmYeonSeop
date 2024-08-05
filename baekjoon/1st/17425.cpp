#include <iostream>

using namespace std;

#define ll	long long

ll dp[1000005], MAX = 1000001;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t, n;
	cin >> t;

	for (int i = 1; i < MAX; ++i)
	{
		for (int j = i; j < MAX; j+=i)
			dp[j] += i;
		dp[i] += dp[i - 1];
	}

	for (int i = 0; i < t; ++i)
	{
		cin >> n;
		cout << dp[n] << "\n"; // 쓰레기 같은 endl
	}
	return (0);
}