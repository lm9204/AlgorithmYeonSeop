#include <iostream>
#include <cmath>

using namespace std;

int n, d, k, c;
int sushi[3000005];
int v[3005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; ++i)
		cin >> sushi[i];

	int ans = 0, size = 0, coupon = 1;
	for (int i = 0; i < k; ++i)
	{
		if (!v[sushi[i]]++)
			size++;
	}

	if (v[c])
		coupon = 0;
	else
		coupon = 1;
	ans = max(ans, size + coupon);

	for (int i = k; i < n + k; ++i)
	{
		if (!--v[sushi[(i - k) % n]])
			size--;
		if (!v[sushi[i % n]]++)
			size++;

		if (v[c])
			coupon = 0;
		else
			coupon = 1;
		ans = max(ans, size + coupon);
	}
	cout << ans << "\n";
	return (0);
}