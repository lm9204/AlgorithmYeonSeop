#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, k;
long long ans = 0;
queue<int> sub[21];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;

	string word;
	for (int i = 0; i < n; ++i)
	{
		cin >> word;
		int len = word.length();

		while (!sub[len].empty() && i - sub[len].front() > k)
			sub[len].pop();
		ans += sub[len].size();
		sub[len].push(i);
	}

	cout << ans;
}