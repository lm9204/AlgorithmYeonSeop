#include <iostream>
#include <algorithm>

using namespace std;

int d, n;
int oven[300003];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> d >> n;
	for (int i = 0; i < d; ++i)
		cin >> oven[i];

	for (int i = 1; i < d; ++i)
		oven[i] = min(oven[i], oven[i - 1]);
	
	int ans = d;
	for (int i = 0; i < n; ++i)
	{
		int pizza, prev = ans;
		cin >> pizza;

		int left = 0, right = ans - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (oven[mid] >= pizza)
				left = mid + 1;
			else
				right = mid - 1;
		}
		ans = right;
	}

	if (ans < 0)
		cout << 0;
	else
		cout << ans + 1;
	return (0);
}