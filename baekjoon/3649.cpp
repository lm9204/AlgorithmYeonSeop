#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int width, n;
	int lego[1000005];

	while (cin >> width >> n)
	{

		width *= 10000000;
		for (int j = 0; j < n; ++j)
			cin >> lego[j];

		sort(lego, lego + n);
		
		int fr = 0, ed = max(n - 1, 0);

		while (fr != ed)
		{
			if (lego[fr] + lego[ed] == width)
			{
				cout << "yes " << lego[fr] << " " << lego[ed] << "\n";
				break;
			}
			if (lego[fr] + lego[ed] > width)
				ed--;
			else
				fr++;
		}
		if (fr == ed)
			cout << "danger" << "\n";
	}
	return (0);
}