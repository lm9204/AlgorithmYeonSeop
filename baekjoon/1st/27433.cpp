#include <iostream>

using namespace std;

#define ll long long

ll fact(int n)
{
	if (n <= 1)
		return 1;
	return n * fact(n - 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	cout << fact(n);
	return (0);
}