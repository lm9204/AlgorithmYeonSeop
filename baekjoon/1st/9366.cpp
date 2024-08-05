#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int a, b, c, maxLine, sum;
		cin >> a >> b >> c;
		cout << "Case #" << i + 1 << ": ";
		
		maxLine = max(a, max(b, c));

		if (maxLine == a)
			sum = b + c;
		else if (maxLine == b)
			sum = a + c;
		else
			sum = a + b;

		if (maxLine >= sum)
			cout << "invalid!" << endl;
		else if (a == b && b == c)
			cout << "equilateral" << endl;
		else if (a == b || b == c || a == c)
			cout << "isosceles" << endl;
		else
			cout << "scalene" << endl;
	}
	return (0);
}