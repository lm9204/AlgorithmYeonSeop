#include <iostream>
#include <cstring>

using namespace std;

int n, m, cnt = 0;
int arr[505][505];
int dp[505][505];

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int dfs(int x, int y)
{
	if (x == n - 1 && y == m - 1)
		return (1);

	if (dp[y][x] != -1)
		return dp[y][x];

	dp[y][x] = 0;

	for (int i = 0; i < 4; ++i)
	{
		int dy = y + dir[i][0];
		int dx = x + dir[i][1];

		if (dx >= 0 && dx < n && dy >= 0 && dy < m && arr[dy][dx]< arr[y][x])
			dp[y][x] += dfs(dx, dy);
	}

	return dp[y][x];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> m >> n;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];

	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0) << "\n";
	return (0);
}
