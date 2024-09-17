#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
vector<int> house;

bool canPlaceRouters(int minDist)
{
	int count = 1;
	int lastPos = house[0];

	for (int i = 1; i < n; ++i)
	{
		if (house[i] - lastPos >= minDist)
		{
			count++;
			lastPos = house[i];
			if (count >= c) return true;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; ++i)
	{
		int n;
		cin >> n;
		house.push_back(n);
	}

	sort(house.begin(), house.end());

	int left = 1, right = house.back() - house.front(), ans = 0;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (canPlaceRouters(mid))
		{
			ans = mid;	
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << ans;
	
	return (0);
}