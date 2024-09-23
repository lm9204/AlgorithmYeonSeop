#include <iostream>
#include <algorithm>

#define ll long long

int arr[100005];
int n, m;


using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr, arr + n);

	int left = 0, right = 0;	
	ll MIN = 2000000000;
	while (left < n - 1)
	{
		ll gap = arr[right] - arr[left];
		if (gap >= m)
		{
			if (MIN > gap)
				MIN = gap;
			left++;
		}
		else if (gap < m)
		{
			if (n - 1 > right)
				right++;
			else
				left++;
		}
	}

	cout << MIN;
	return (0);
}