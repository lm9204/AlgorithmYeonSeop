#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, layer = 1, prev = 1;

	cin >> n;

	if (n == 1)
	{
		cout << "1";
		return (0);
	}

	while (prev + layer * 6 < n)
	{
		prev += layer * 6;
		layer++;
	}

	cout << layer + 1;

	return (0);
}