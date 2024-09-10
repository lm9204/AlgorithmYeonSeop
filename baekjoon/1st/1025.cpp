#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;
int arr[10][10];

bool	isSquare(int n)
{
	int root = (int)sqrt(n);
	return root * root == n;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;

	string s;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		for (int j = 0; j < m; ++j)
			arr[i][j] = s[j] - '0';
	}

	int ans = -1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			for (int x = -n; x < n; ++x)
				for (int y = -m; y < m; ++y)
				{
					if (!x && !y) continue;
					int r = i, c = j, num = 0;
					while (0 <= r && r < n && 0 <= c && c < m)
					{
						num *= 10;
						num += arr[r][c];
						r += x, c += y;
						if (isSquare(num)) ans = max(ans, num);
					}
				}
	cout << ans;
	return (0);
}