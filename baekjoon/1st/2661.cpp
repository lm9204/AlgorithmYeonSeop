#include <iostream>
#include <string>

using namespace std;

int n;

bool	dfs(string& ans, int idx)
{
	if (idx > 0)
	{
		for (int i = 0; i < ans.length(); ++i)
		{
			for (int j = 1; j <= ans.length() / 2; ++j)
			{
				string sub = ans.substr(i, j);
				if (ans.find(sub, i + 1) == i + j)
					return false;
			}
		}
	}

	if (idx == n)
		return true;
	for (int i = 1; i < 4; ++i)
	{
		if (idx != 0 && ans[idx - 1] == i + '0') continue;
		ans.push_back(i + '0');
		if (dfs(ans, idx + 1))
			return true;
		ans.erase(idx);
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	string ans;

	dfs(ans, 0);
	cout << ans << "\n";
	return (0);
}