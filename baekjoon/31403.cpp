#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string a, b;
	int c;
	cin >> a >> b >> c;
	cout << stoi(a) + stoi(b) - c << endl;
	a.append(b);

	cout << stoi(a) - c << endl;
}