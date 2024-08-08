#include <iostream>
#include <vector>
#include <cmath>

#define ll long long

using namespace std;

int s[21];
vector<int> p;

ll factorial(ll num)
{
	if (num <= 1)
		return 1;
	return num * factorial(num - 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	ll k;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		p.push_back(i + 1);

	if (m == 1)
	{
		cin >> k;
		int idx = 1;

		k--;
		for (int i = 0; i < n; ++i)
		{
			ll r = factorial(n - i - 1);
			ll idx = k / r;
			k %= r;
			s[i] = p[idx];
			p.erase(p.begin() + idx);
		}

		for (int i = 0; i < n; ++i)
			cout << s[i] << " ";
		cout << "\n";
	}
	
	if (m == 2)
	{
		ll ans = 1;
		for (int i = 0; i < n; ++i)
			cin >> s[i];
		
		for (int i = 0; i < n; ++i)
		{
			ll range = factorial(n - i - 1);
			int j = 0;
			for (; j < n; ++j)
				if (s[i] == p[j])
				{
					p.erase(p.begin() + j);
					break;
				}
			if (j != 0)
				ans += range * j;
		}
		cout << ans;
	}
	return (0);
}