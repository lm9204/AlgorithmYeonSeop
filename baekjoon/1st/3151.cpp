#include <iostream>
#include <algorithm>

using namespace std;

int arr[10001];
int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	
	long long count = 0;
	sort(arr, arr + n);

	for (int i = 0; i < n - 2; ++i)
	{
		int target = -arr[i], left = i + 1, right = n - 1;
		while (left < right)
		{
			int cur = arr[left] + arr[right];
			if (cur == target)
			{
				int curl = arr[left], curr = arr[right];
				if (curl == curr)
				{
					int len = right - left + 1;
					count += len * (right - left) / 2;
					break;
				}
				else
				{
					int dl = 0, dr = 0;

					while (arr[left] == curl)
					{
						dl++;
						left++;
					}
					while (arr[right] == curr)
					{
						dr++;
						right--;
					}
					count += dl * dr;
				}
			}
			else if (cur < target)
				left++;
			else if (cur > target)
				right--;
		}
	}
	cout << count;
	return (0);
}