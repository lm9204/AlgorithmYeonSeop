#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int l;
	cin >> l;

	for (int i = 1; i <= l; ++i)
	{
		if (i * 5 >= l)
		{
			cout << i;
			return (0);
		}
	}

}