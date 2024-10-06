#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int a, b;
	cin >> a >> b;
	for (int i = 0; i < a; ++i)
		cin >> b >> b;

	cout << "비와이";
	return (0);
}