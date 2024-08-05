#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int num, ans = 0;;
	for (int i = 0; i < 6; ++i)
	{
		cin >> num;
		ans += num * 5;
	}
	cout << ans;
	return (0);
}