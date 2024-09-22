#include <iostream>
#include <algorithm>
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
			break;
			
		int MAX = max(a, max(c, b));
		int n1, n2;

		if (MAX == a)
			n1 = b, n2 = c;
		else if (MAX == b)
			n1 = a, n2 = c;
		else
			n1 = a, n2 = b;
		
		if (pow(MAX, 2) == pow(n1, 2) + pow(n2, 2))
			cout << "right\n";
		else
			cout << "wrong\n";
	}

	return (0);
}