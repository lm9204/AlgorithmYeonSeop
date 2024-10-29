#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, l;

vector<int> spot;
vector<pair<int, int> > animals;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> m >> n >> l;
	for (int i = 0; i < m; ++i)
	{
		int sl; cin >> sl;
		spot.push_back(sl);
	}

	for (int i = 0; i < n; ++i)
	{
		int x, y; cin >> x >> y;
		if (l >= y)
			animals.push_back({ x, l - y });
	}

	sort(spot.begin(), spot.end());

	int ans = 0;
	for (size_t i = 0; i < animals.size(); ++i)
	{
		int low = 0, high = spot.size() - 1, left = animals[i].first - animals[i].second, right = animals[i].first + animals[i].second;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (left <= spot[mid] && spot[mid] <= right)
			{
				ans++;
				break;
			}
			if (spot[mid] > animals[i].first)
				high = mid - 1;
			else
				low = mid + 1;
		}
	}

	cout << ans;
	return (0);
}