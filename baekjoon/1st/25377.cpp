#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, MIN = 1001;
	cin >> n;

	while (n--)
	{
		int a, b;
		cin >> a >> b;

		if (a <= b)
			MIN = min(MIN, b);
	}
	if (MIN == 1001)
		cout << -1;
	else
		cout << MIN;
	return (0);
}