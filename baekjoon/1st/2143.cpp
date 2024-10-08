#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, m;
int a[1001], b[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> t >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	cin >> m;
	for (int i = 0; i < m; ++i)
		cin >> b[i];

	vector<int> asum, bsum;

	for (int i = 0; i < n; ++i)
	{
		int sum = a[i];
		asum.push_back(sum);
		for (int j = i + 1; j < n; ++j)
		{
			sum += a[j];
			asum.push_back(sum);
		}
	}

	for (int i = 0; i < m; ++i)
	{
		int sum = b[i];
		bsum.push_back(sum);
		for (int j = i + 1; j < m; ++j)
		{
			sum += b[j];
			bsum.push_back(sum);
		}
	}

	sort(bsum.begin(), bsum.end());
	long long ans = 0;
	for (int i = 0; i < asum.size(); ++i)
	{
		int target = t - asum[i];
		int lo = lower_bound(bsum.begin(), bsum.end(), target) - bsum.begin();
		int hi = upper_bound(bsum.begin(), bsum.end(), target) - bsum.begin();

		ans += (hi - lo);
	}

	cout << ans;
	return (0);
}