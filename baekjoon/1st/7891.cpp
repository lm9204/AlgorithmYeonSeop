#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		long long n1, n2;
		cin >> n1 >> n2;

		cout << n1 + n2 << "\n";
	}

	return (0);
}