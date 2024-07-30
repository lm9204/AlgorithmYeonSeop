#include <iostream>
#include <cmath>

using namespace std;

int arr[1000005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int m, n;
	cin >> m >> n;

	for (int i = 2; i <= n; ++i)
		arr[i] = 1;

	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (!arr[i]) continue;

		for (int j = i * 2; j <= n; j+=i)
			arr[j] = 0;
	}

	for (int i = m; i <= n; ++i)
	{
		if (arr[i])
			cout << i << "\n";
	}
}