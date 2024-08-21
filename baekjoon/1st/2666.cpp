#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[21];
int	dp[21][21][21];
int open1, open2;
int n, m;

int solve(int o1, int o2, int cnt)
{
	if (cnt == m + 1)
		return (0);

	int& ret = dp[o1][o2][cnt];
	if (ret != -1)
		return ret;
	ret = 0;
	ret = min(abs(arr[cnt] - o1) + solve(arr[cnt], o2, cnt + 1), abs(arr[cnt] - o2) + solve(o1, arr[cnt], cnt + 1));
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dp, -1, sizeof(dp));

	cin >> n;
	cin >> open1 >> open2;

	cin >> m;
	for (int i = 1; i <= m; ++i)
		cin >> arr[i];

	cout << solve(open1, open2, 1);

	return (0);
}