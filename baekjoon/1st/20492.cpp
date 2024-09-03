#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	cout << int(n - (n * 0.22)) << " " << int(n - (n * 0.2 * 0.22));

	return (0);
}