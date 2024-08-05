#include <iostream>
#include <string>

using namespace std;

string label = "WelcomeToSMUPC";

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	cout << label[(n - 1) % 14];
	return (0);
}