#include <iostream>
#include <algorithm>

#define ull unsigned long long

using namespace std;

ull arr[100005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ull n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr, arr + n);
	ull low = 0, high = m * arr[0], ans = 0, mid, count;
	while (low <= high)
	{
		count = 0;
		mid = low + (high - low) / 2;
		for (int i = 0; i < n; ++i)
			count += mid / arr[i];
		if (count >= m)
		{
			ans = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	cout << ans;
	return (0);
}