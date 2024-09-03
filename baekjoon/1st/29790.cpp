#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, u, l;
	cin >> n >> u >> l;

	if (n >= 1000 && (u >= 8000 || l >= 260))
		cout << "Very Good\n";
	else if (n >= 1000)
		cout << "Good\n";
	else
		cout << "Bad\n";
	return (0);
}