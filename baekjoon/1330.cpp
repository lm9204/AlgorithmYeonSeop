#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n1, n2;
	cin >> n1 >> n2;

	if (n1 > n2)
		cout << ">" << endl;
	else if (n1 < n2)
		cout << "<" << endl;
	else
		cout << "==" << endl;
	return (0);
}