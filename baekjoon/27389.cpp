#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	float n;
	cin >> n;

	float f = n / 4.0;
	int place = 1;
	if (fabs(f - floor(f) > 0.009))
		place = 2;

	cout << fixed << setprecision(place) << f << endl;
	return (0);
}