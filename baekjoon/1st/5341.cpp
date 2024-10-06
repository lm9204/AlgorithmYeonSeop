#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;

		int sum = n;
		while (n--)
			sum += n;

		cout << sum << "\n";
	}

	return (0);
}