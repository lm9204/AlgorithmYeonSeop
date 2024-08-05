#include <iostream>
#include <cmath>

using namespace std;

int arr[100005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int fr = 0, ed = n - 1;
	int MIN = arr[fr] + arr[ed];

	while (fr < ed)
	{
		if (abs(arr[fr] + arr[ed]) < abs(MIN))
			MIN = arr[fr] + arr[ed];
		if (arr[fr] + arr[ed] < 0)
			fr++;
		else
			ed--;
	}
	cout << MIN << "\n";
	return (0);
}