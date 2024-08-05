#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string word;
	int i;

	cin >> word >> i;
	cout << word[i - 1];
	return (0);
}