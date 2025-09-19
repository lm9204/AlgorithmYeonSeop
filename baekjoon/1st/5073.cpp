#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int a, b, c;
	while (cin >> a >> b >> c)
	{
		if (a == 0 && b == 0 && c == 0)
			return (0);

		int max_line = max(a, max(b, c));
		if (max_line >= a + b + c - max_line)
			cout << "Invalid\n";
		else if (a == b && b == c)
			cout << "Equilateral\n";
		else if (a != b && b != c && a != c)
			cout << "Scalene\n";
		else
			cout << "Isosceles\n";
	}
	return (0);
}