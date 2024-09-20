#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[101];
vector<int> divisors;

int gcd(int a, int b)
{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr, arr + n);

	int cur_gcd = arr[1] - arr[0];
	for (int i = 2; i < n; ++i)
		cur_gcd = gcd(cur_gcd, arr[i] - arr[i - 1]);

	for (int i = 1; i * i <= cur_gcd; ++i)
	{
		if (cur_gcd % i == 0)
		{
			divisors.push_back(i);
			if (i != cur_gcd / i)
				divisors.push_back(cur_gcd / i);
		}
	}

	sort(divisors.begin(), divisors.end());
	for (int d : divisors)
		if (d != 1)
			cout << d << "\n";
	return (0);
}