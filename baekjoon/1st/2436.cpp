#include <iostream>
#include <cmath>

using namespace std;

#define ll long long

int GCD(int a, int b)
{
	if (b == 0) return a;
	return GCD(b, a % b);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int gcd, lcm, A, B;
	cin >> gcd >> lcm;

	ll d = lcm / gcd;
	for (int i = 1; i <= sqrt(d); ++i)
	{
		if (d % i == 0)
		{
			ll a = i, b = d / i;

			if (GCD(a, b) == 1)
			{
				A = a;
				B = b;
			}
		}
	}
	cout << A * gcd << " " << B * gcd << "\n";
	return (0);
}