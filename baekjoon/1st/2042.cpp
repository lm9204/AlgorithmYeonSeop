#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	long n, m;
	cin >> n >> m;

	cout << abs(n - m);
}