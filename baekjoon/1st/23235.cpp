#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, idx = 1;
	while (cin >> n)
	{
		if (n == 0)
			break;

		int v;
		for (int i = 0; i < n; ++i)
			cin >> v;
		
		cout << "Case " << idx << ": Sorting... done!\n";
		idx++;
	}
	return (0);
}