#include <iostream>

using namespace std;

#define ull unsigned long long

int arr[10000005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ull a, b;
	cin >> a >> b;

	ull ans = 0;
	for (ull i = 2; i * i <= b; ++i)
		arr[i] = 1;

	for (ull i = 2; i * i <= b; ++i)
	{
		if (!arr[i]) continue;
		for (ull j = i * 2; j * j <= b; j+=i)
			arr[j] = 0;
		
		ull num = i * i;
		while (num <= b)
		{
			if (a <= num)
				ans++;
			if (num > b / i) break;
			num *= i;
		}
	}

	cout << ans << "\n";
	return (0);
}