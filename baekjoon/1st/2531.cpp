#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int	arr[30005];
int check[30005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, d, k, c;
	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		int flag = 0;
		int coupon = 1;
		for (int j = i; j < i + k; j++)
		{
			if (!check[arr[j % n]])
				check[arr[j % n]] = 1;
			else
				flag++;
		}
		if (check[c])
			coupon = 0;
		count = max(count, k - flag + coupon);
		memset(check, false, sizeof(check));
	}

	cout << count << endl;
	return (0);
}