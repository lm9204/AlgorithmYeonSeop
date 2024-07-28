#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <set>

using namespace std;

int n, k, ans;
bool	alpha[26];
vector<string> v;

void dfs(int idx, int remain)
{
	if (!remain)
	{
		int cnt = 0;
		for (string elem : v)
		{
			bool flag = true;
			for (char ch : elem)
			{
				if (!alpha[ch - 'a'])
				{
					flag = false;
					break ;
				}
			}
			if (flag) cnt++;
		}
		ans = max(ans, cnt);
		if (ans == n)
		{
			cout << n << endl;
			exit(0);
		}
	}
	
	for (int i = idx; i < 26; ++i)
	{
		if (alpha[i]) continue;
		alpha[i] = true;
		dfs(i, remain - 1);
		alpha[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	string str;
	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		v.push_back(str.substr(4, str.length() - 8));
	}

	if (k < 5)
	{
		cout << 0 << endl;
		return (0);
	}

	alpha[0] = true;
	alpha[2] = true;
	alpha[8] = true;
	alpha[13] = true;
	alpha[19] = true;

	dfs(0, k - 5);
	cout << ans << endl;
	return (0);
}